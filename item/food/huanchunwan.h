//huanchunwan.h 还春丸

FOOD_BEGIN(CIhuanchunwan);

virtual void create(int nFlag = 0)		
{
	set_name( "还春丸");	
	set_weight(700);
	set("unit", "颗");
	set("long", "这是一颗碧绿的药丸,上面刻着一行小字，仔细一看，原来写的是“韦春花亲造丹药，只此一家，有假包换”。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("per")<38)
	{
		me->add("per", 1);
		message_vision("$HIR$N吞下一颗还春丹，突然感到一股电流穿过身体般的颤栗，脸色由青转白，由白转红。\n心中不禁暗自得意“这韦春花的手艺还真不错”!\n$N的魅力增加了！", me);
	}
	destruct(this);
	return 1;

}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



