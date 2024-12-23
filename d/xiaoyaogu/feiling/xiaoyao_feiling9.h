//xiaoyao_feiling9.h ·ÉÁèÖ®ÓÒ×ãÊÒ
//ÇØ²¨ 2003¡¢3¡¢15

XiaoYao_BEGIN(CRXiaoYao_feiling9);

virtual void create()
{
	set_name( "·ÉÁèÖ®ÓÒ×ãÊÒ");
	set("no_autosave",1);
	set("index",9);

	add_item("shicheng");

	add_door("·ÉÁèÖ®ÓÒ±ÛÊÒ", "åĞÒ£¹È·ÉÁèÖ®ÓÒ±ÛÊÒ", "åĞÒ£¹È·ÉÁèÖ®ÓÒ×ãÊÒ");
	add_door("·ÉÁèÖ®ÂÄ", "åĞÒ£¹È·ÉÁèÖ®ÂÄ", "åĞÒ£¹È·ÉÁèÖ®ÓÒ×ãÊÒ");

};

XiaoYao_END;
