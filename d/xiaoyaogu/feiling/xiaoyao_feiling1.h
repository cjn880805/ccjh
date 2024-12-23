//xiaoyao_feiling1.h ·ÉÁèÖ®×ó¼çÊÒ
//ÇØ²¨ 2003¡¢3¡¢15

XiaoYao_BEGIN(CRXiaoYao_feiling1);

virtual void create()
{
	set_name( "·ÉÁèÖ®×ó¼çÊÒ");
	set("no_autosave",1);
	set("index",1);

	add_item("shicheng");
	add_door("·ÉÁèÖ®×ó±ÛÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó±ÛÊÒ", "åĞÒ£¹È·ÉÁèÖ®×ó¼çÊÒ");
	add_door("·ÉÁèÖ®Ã±", "åĞÒ£¹È·ÉÁèÖ®Ã±", "åĞÒ£¹È·ÉÁèÖ®×ó¼çÊÒ");

};

XiaoYao_END;
