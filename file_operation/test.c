struct nand_chip {
   struct mtd_info parent;
		struct mtd_info {
				uint32_t flags;
				struct block_device bdev;
				union {
				struct list_head master_node; 
				struct list_head slave_node;
				};
				
				union {
				struct list_head slave_list;
				struct mtd_info *master;
				};
				
				int   type;
				char  name[MTD_ID_NAME_LEN]; 
				size_t write_size;
				size_t erase_size;
				size_t chip_size; 
				__u32 write_shift;
				__u32 erase_shift;
				__u32 chip_shift;
				__u32 oob_size;
				struct ecc_stats eccstat;
				
				int bad_allow;
				FLASH_HOOK_PARAM *callback_args;
				FLASH_HOOK_FUNC   callback_func;
				
				int (*read)(struct mtd_info *, __u32, __u32, size_t *, __u8 *);
				int (*write)(struct mtd_info *, __u32, __u32 , __u32 *, const __u8 *);
				int (*erase)(struct mtd_info *, struct erase_info *);
				
				int (*read_oob)(struct mtd_info *, __u32, struct mtd_oob_ops *);
				int (*write_oob)(struct mtd_info *,__u32, struct mtd_oob_ops *);
				
				int (*block_isbad)(struct mtd_info *, __u32);
				int (*block_markbad)(struct mtd_info *, __u32);
				int (*scan_bad_block)(struct mtd_info *); 
				OOB_MODE oob_mode;
				struct nand_ecclayout *ecclayout;
		};

   struct nand_ctrl *master;                      
		struct nand_ctrl {
				void  *cmmd_reg;
				void  *addr_reg;
				void  *data_reg;
				
				int   slaves;//slave number_th 
				__u32   max_slaves; //slave total
				
				int   chip_delay;//?
				NAND_STATE  state;
				
				private :
				__u8    (*read_byte)(struct nand_ctrl *);
				__u16   (*read_word)(struct nand_ctrl *);
				void  (*write_buff)(struct nand_ctrl *, const __u8 *, int);
				void  (*read_buff)(struct nand_ctrl *, __u8 *, int);
				int   (*verify_buff)(struct nand_ctrl *, const __u8 *, int);
				void  (*select_chip)(struct nand_chip *, bool);
				int   (*block_bad)(struct nand_chip *, __u32, int);
				int   (*block_markbad)(struct nand_chip *, __u32);
				void  (*cmd_ctrl)(struct nand_chip *, int, unsigned int);
				int   (*flash_ready)(struct nand_chip *);
				void  (*command)(struct nand_chip * nand, __u32 cmd, int col, int row);
				int   (*wait_func)(struct nand_chip *);
				void  (*erase_block)(struct nand_chip *, int);
				int   (*scan_bad_block)(struct nand_chip *);
				public:
				int   (*read_page)(struct nand_chip *, __u8 *);
				void  (*write_page)(struct nand_chip *, const __u8 *);
				int   (*read_page_raw)(struct nand_chip *, __u8 *);
				void  (*write_page_raw)(struct nand_chip *, const __u8 *);
				int   (*read_oob)(struct nand_chip *, int, int);
				int   (*write_oob)(struct nand_chip *, int);
				
				ECC_MODE ecc_mode;
				
				struct nand_oob_layout *hard_oob_layout;
				struct nand_oob_layout *soft_oob_layout;
				struct nand_oob_layout *curr_oob_layout;
				
				__u32  ecc_data_len;
				__u32  ecc_code_len;
				
				void  (*ecc_enable)(struct nand_chip *nand, int mode); 
				int   (*ecc_generate)(struct nand_chip *nand, const __u8 *data, __u8 *ecc);
				int   (*ecc_correct)(struct nand_chip *nand, __u8 *data, __u8 *ecc_read, __u8 *ecc_calc);
				
				const char *name;
				
				struct list_head nand_list;
		};
   __u32  device_id;
   __u32  vendor_id;                                 
   __u32  flags;                             
   int  phy_erase_shift;
   int  bbt_erase_shift;
   int  page_num_mask;
   int  page_in_buff;                                            
   int  bad_blk_oob_pos;                                                
   struct mtd_oob_ops opt;
		struct mtd_oob_ops {
				unsigned int	mode;
				size_t		len;
				size_t		retlen;
				size_t		ooblen;
				size_t		oobretlen;
				uint32_t	ooboffs;
				uint8_t		*datbuf;
				uint8_t		*oobbuf;
		};

   __u8 *bbt;
   __u8 *oob_buf;
   struct nand_buffer *buffers; 
		struct nand_buffer {
				__u8 ecccalc[NAND_MAX_OOB_SIZE];
				__u8 ecccode[NAND_MAX_OOB_SIZE];
				__u8 data_buff[NAND_MAX_PAGESIZE + NAND_MAX_OOB_SIZE];
		};

   struct nand_bad_blk *bbt_td;
   struct nand_bad_blk *bbt_md;
   struct nand_bad_blk *bad_blk_patt;
		struct nand_bad_blk {
				int flags;
				int pages[NAND_MAX_CHIPS];
				int offs;
				int veroffs;
				int len;
				int maxblocks;
				int reserved_block_code;
				__u8  version[NAND_MAX_CHIPS];
				__u8 *pattern;
		};

   __u32 bus_idx;
   const char *name;
   struct list_head nand_node;
		   struct list_head {
				struct list_head *next, *prev;
		   };
 };

