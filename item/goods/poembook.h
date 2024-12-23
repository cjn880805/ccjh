ITEM_BEGIN(CIpoembook)

virtual void create(int nFlag = 0)		
{
	set_name("唐诗选辑", "poembook");
    set_weight(500);
    set("unit", "本");
    set("material", "paper");
	set("is_poem",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_get",1);
	call_out(selfdest, random(300) + 1);
};


static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(userp(me))
		tell_object((CChar *)me, "突然一阵风吹过，唐诗选辑在风中化为寸寸碎纸，若蝴蝶般顺风飞去了。");
	else
		tell_room(me, "突然一阵风吹过，唐诗选辑在风中化为寸寸碎纸，若蝴蝶般顺风飞去了。");

	destruct(ob);
	return;
}



ITEM_END;
