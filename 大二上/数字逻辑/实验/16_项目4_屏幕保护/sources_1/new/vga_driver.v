`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/08 23:57:11
// Design Name: 
// Module Name: vga_driver
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module vga_driver
(
    input                   I_clk   , // ϵͳ50MHzʱ��
    input                   I_rst_n , // ϵͳ��λ
    output   reg   [3:0]    O_red   , // VGA��ɫ����
    output   reg   [3:0]    O_green , // VGA��ɫ����
    output   reg   [3:0]    O_blue  , // VGA��ɫ����
    output                  O_hs    , // VGA��ͬ���ź�
    output                  O_vs      // VGA��ͬ���ź�
);

// �ֱ���Ϊ640*480ʱ��ʱ�������������
parameter       C_H_SYNC_PULSE      =   96      , 
                C_H_BACK_PORCH      =   48      ,
                C_H_ACTIVE_TIME     =   640     ,
                C_H_FRONT_PORCH     =   16      ,
                C_H_LINE_PERIOD     =   800     ;
                                                
// �ֱ���Ϊ640*480ʱ��ʱ�������������                   
parameter       C_V_SYNC_PULSE      =   2       , 
                C_V_BACK_PORCH      =   33      ,
                C_V_ACTIVE_TIME     =   480     ,
                C_V_FRONT_PORCH     =   10      ,
                C_V_FRAME_PERIOD    =   525     ;
                                                
parameter       C_IMAGE_WIDTH       =   128     ,
                C_IMAGE_HEIGHT      =   128     ,
                C_IMAGE_PIX_NUM     =   16384   ;
                

reg     [11:0]      R_h_cnt         ; // ��ʱ�������
reg     [11:0]      R_v_cnt         ; // ��ʱ�������
reg                 R_clk_25M       ;
reg     [13:0]      R_rom_addr      ; // ROM�ĵ�ַ
wire    [11:0]      W_rom_data      ; // ROM�д洢������

reg     [11:0]      R_h_pos         ; // ͼƬ����Ļ����ʾ��ˮƽλ�ã�����Ϊ0ʱ��ͼƬ������Ļ�������
reg     [11:0]      R_v_pos         ; // ͼƬ����Ļ����ʾ�Ĵ�ֱλ�ã�����Ϊ0ʱ��ͼƬ������Ļ���ϱ���

reg                 R_vs_reg1       ;
reg                 R_vs_reg2       ;
wire                W_vs_neg        ; // �������½��ر�־
reg     [1:0]       R_state         ;

wire                W_active_flag   ; // �����־��������ź�Ϊ1ʱRGB�����ݿ�����ʾ����Ļ��

//���ܣ� ����25MHz������ʱ��
always @(posedge I_clk or negedge I_rst_n)
begin
    if(!I_rst_n)
        R_clk_25M   <=  1'b0        ;
    else
        R_clk_25M   <=  ~R_clk_25M  ;     
end

// ���ܣ�������ʱ��
always @(posedge R_clk_25M or negedge I_rst_n)
begin
    if(!I_rst_n)
        R_h_cnt <=  12'd0   ;
    else if(R_h_cnt == C_H_LINE_PERIOD - 1'b1)
        R_h_cnt <=  12'd0   ;
    else
        R_h_cnt <=  R_h_cnt + 1'b1  ;                
end                

assign O_hs =   (R_h_cnt < C_H_SYNC_PULSE) ? 1'b0 : 1'b1    ; 

// ���ܣ�������ʱ��
always @(posedge R_clk_25M or negedge I_rst_n)
begin
    if(!I_rst_n)
        R_v_cnt <=  12'd0   ;
    else if(R_v_cnt == C_V_FRAME_PERIOD - 1'b1)
        R_v_cnt <=  12'd0   ;
    else if(R_h_cnt == C_H_LINE_PERIOD - 1'b1)
        R_v_cnt <=  R_v_cnt + 1'b1  ;
    else
        R_v_cnt <=  R_v_cnt ;                        
end                

assign O_vs =   (R_v_cnt < C_V_SYNC_PULSE) ? 1'b0 : 1'b1    ; 
assign W_active_flag =  (R_h_cnt >= (C_H_SYNC_PULSE + C_H_BACK_PORCH                      ))  &&
                        (R_h_cnt <= (C_H_SYNC_PULSE + C_H_BACK_PORCH + C_H_ACTIVE_TIME     ))  && 
                        (R_v_cnt >= (C_V_SYNC_PULSE + C_V_BACK_PORCH                      ))  &&
                        (R_v_cnt <= (C_V_SYNC_PULSE + C_V_BACK_PORCH + C_V_ACTIVE_TIME     ))  ;   

// load the data from rom
always @(posedge R_clk_25M or negedge I_rst_n)
begin
    if(!I_rst_n) 
        R_rom_addr  <=  14'd0 ;
    else if(W_active_flag)     
        begin
            if(R_h_cnt >= (C_H_SYNC_PULSE + C_H_BACK_PORCH + R_h_pos                        )  && 
               R_h_cnt <= (C_H_SYNC_PULSE + C_H_BACK_PORCH + R_h_pos + C_IMAGE_WIDTH  - 1'b1)  &&
               R_v_cnt >= (C_V_SYNC_PULSE + C_V_BACK_PORCH + R_v_pos                        )  && 
               R_v_cnt <= (C_V_SYNC_PULSE + C_V_BACK_PORCH + R_v_pos + C_IMAGE_HEIGHT - 1'b1)  )
                begin
                    O_red       <= W_rom_data[11:8]    ;
                    O_green     <= W_rom_data[7:4]     ;
                    O_blue      <= W_rom_data[3:0]      ;
                    if(R_rom_addr == C_IMAGE_PIX_NUM - 1'b1)
                        R_rom_addr  <=  14'd0 ;
                    else
                        R_rom_addr  <=  R_rom_addr  +  1'b1 ;         
                end
            else
                begin
                    O_red       <=  3'd0        ;
                    O_green     <=  3'd0        ;
                    O_blue      <=  3'd0        ;
                    R_rom_addr  <=  R_rom_addr  ;
                end                          
        end
    else
        begin
            O_red       <=  3'd0        ;
            O_green     <=  3'd0        ;
            O_blue      <=  3'd0        ;
            R_rom_addr  <=  R_rom_addr  ;
        end          
end

// move the img
always @(posedge R_clk_25M or negedge I_rst_n)
begin
    if(!I_rst_n)
        begin
            R_vs_reg1   <=  1'b0        ;
            R_vs_reg2   <=  1'b0        ;
        end
    else
        begin
            R_vs_reg1   <=  O_vs        ;
            R_vs_reg2   <=  R_vs_reg1   ;
        end         
end

assign W_vs_neg = ~R_vs_reg1 & R_vs_reg2 ;

// bounce block
always@(posedge R_clk_25M or negedge I_rst_n)
begin
    if(!I_rst_n)
        begin
            R_h_pos <=  12'd0   ;
            R_v_pos <=  12'd0   ; 
            R_state <=  2'b00   ;
        end
    else if(W_vs_neg)    
        begin 
            case(R_state)
                2'b00: // ͼƬ�����·��ƶ�
                    begin 
                        R_h_pos     <=  R_h_pos + 1 ;
                        R_v_pos     <=  R_v_pos + 1 ;
                        if(R_h_pos + C_IMAGE_WIDTH == C_H_ACTIVE_TIME) // ��������ұ߿�
                            R_state <=  2'b10       ;
                        else if((R_v_pos + C_IMAGE_HEIGHT) == C_V_ACTIVE_TIME) // ��������±߿�
                            R_state <=  2'b01       ;                            
                    end
                2'b01: // ͼƬ�����Ϸ��ƶ�
                    begin 
                        R_h_pos     <=  R_h_pos + 1 ;
                        R_v_pos     <=  R_v_pos - 1 ;
                        if(R_h_pos + C_IMAGE_WIDTH == C_H_ACTIVE_TIME) // ��������ұ߿�
                            R_state <=  2'b11       ;
                        else if(R_v_pos == 1)     // ��������ϱ߿�
                            R_state <=  2'b00       ;
                    end
                2'b10: // ͼƬ�����·��ƶ�
                    begin 
                        R_h_pos     <=  R_h_pos - 1 ;
                        R_v_pos     <=  R_v_pos + 1 ;
                        if(R_h_pos == 1)    // ���������߿�
                            R_state <=  2'b00       ;
                        else if(R_v_pos + C_IMAGE_HEIGHT == C_V_ACTIVE_TIME) // ��������±߿�
                            R_state <=  2'b11       ;
                    end
                2'b11: // ͼƬ�����Ϸ��ƶ�
                    begin 
                        R_h_pos     <=  R_h_pos - 1 ;
                        R_v_pos     <=  R_v_pos - 1 ;
                        if(R_h_pos == 1)    // ��������ϱ߿�
                            R_state <=  2'b01       ;
                        else if(R_v_pos == 1) // ���������߿�
                            R_state <=  2'b10       ;
                    end
                default:R_state <=  2'b00           ;            
            endcase       
        end
end      

rom_img_12 U_rom_image (
  .clka(R_clk_25M), // input clka
  .addra(R_rom_addr), // input [13 : 0] addra
  .douta(W_rom_data) // output [11 : 0] douta
);

endmodule