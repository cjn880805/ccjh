//xiaoyao_feiling8.h ·ÉÁèÖ®ÂÄ
//ÇØ²¨ 2003¡¢3¡¢15

XiaoYao_BEGIN(CRXiaoYao_feiling8);

virtual void create()
{
	set_name( "·ÉÁèÖ®ÂÄ");
	set("no_autosave",1);
	set("index",8);

	add_item("shicheng");
	add_door("·ÉÁèÖ®×ó×ãÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó×ãÊÒ", "åĞÒ£¹È·ÉÁèÖ®ÂÄ");
	add_door("·ÉÁèÖ®ĞÄ", "åĞÒ£¹È·ÉÁèÖ®ĞÄ", "åĞÒ£¹È·ÉÁèÖ®ÂÄ");
	add_door("·ÉÁèÖ®ÓÒ×ãÊÒ", "åĞÒ£¹È·ÉÁèÖ®ÓÒ×ãÊÒ", "åĞÒ£¹È·ÉÁèÖ®ÂÄ");

};

XiaoYao_END;
