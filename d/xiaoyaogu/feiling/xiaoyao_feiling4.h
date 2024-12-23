//xiaoyao_feiling4.h ·ÉÁèÖ®×ó±ÛÊÒ
//ÇØ²¨ 2003¡¢3¡¢15

XiaoYao_BEGIN(CRXiaoYao_feiling4);

virtual void create()
{
	set_name( "·ÉÁèÖ®×ó±ÛÊÒ");
	set("no_autosave",1);
	set("index",4);

	add_item("shicheng");
	add_door("·ÉÁèÖ®×ó¼çÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó¼çÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó±ÛÊÒ");
	add_door("åĞÒ£¹È·ÉÁèÖ®ĞÄ", "åĞÒ£¹È·ÉÁèÖ®ĞÄ", "åĞÒ£¹È·ÉÁèÖ®×ó±ÛÊÒ");
	add_door("·ÉÁèÖ®×ó×ãÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó×ãÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó±ÛÊÒ");

};

XiaoYao_END;
