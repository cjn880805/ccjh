//xiaoyao_feiling7.h ·ÉÁèÖ®×ó×ãÊÒ
//ÇØ²¨ 2003¡¢3¡¢15

XiaoYao_BEGIN(CRXiaoYao_feiling7);

virtual void create()
{
	set_name( "·ÉÁèÖ®×ó×ãÊÒ");
	set("no_autosave",1);
	set("index",7);

	add_item("shicheng");
	add_door("·ÉÁèÖ®×ó±ÛÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó±ÛÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó×ãÊÒ");
	add_door("·ÉÁèÖ®ÂÄ", "åĞÒ£¹È·ÉÁèÖ®ÂÄ", "åĞÒ£¹È·ÉÁèÖ®×ó×ãÊÒ");

};

XiaoYao_END;
