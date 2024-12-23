//wangqing_shi.h 忘情石
FOOD_BEGIN(CIwangqing_shi);

virtual void create(int nFlag = 0)		
{
	set_name( "忘情石");	
	set_weight(700);
	set("unit", "颗");
	set("long", "这是一颗透明的玉石，晶莹如沧海月明，双手轻抚玉石，你和他（她）的过往一切在刹那间闪烁过晶莹的玉石表面，化入冥冥。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N轻轻含住了忘情石，玉石在瞬间即刻融化为一种液体，渗进你的心中。 ", me);
	if(me->querymap("couple"))
	{
		message_vision("$HIR前尘往事如云烟，再勿相逢再勿念，一缕红娘系过的红线节节断落，自此后，你和他（她），再无瓜葛。\n$N仔细品了一下这咸涩的液体，原来，是一滴为他（她）流过的泪，凝聚成石后又在此刻重新融化。 ", me);
		CUser * targetx;
		char idd[255];
		snprintf(idd,255,"%s",me->querystr("couple/id"));
		targetx=find_online(idd);
		if (targetx)
		{
			tell_object(me, "由于你的伴侣现在在线上，忘情石失去了它的效果。");
			return 1;
		}
		else
		{
			char msg[255];
			targetx = add_user();
			targetx->set("id", me->querystr("couple/id"));
			targetx->LoadFromServer();

			me->set("last_couple_name",me->querystr("couple/name"));
			me->set("last_couple_id",me->querystr("couple/id"));
			
			targetx->set("last_couple_name",targetx->querystr("couple/name"));
			targetx->set("last_couple_id",targetx->querystr("couple/id"));
			
			me->del("couple");
			(CChar *)me->add("couple_betray",1);
			targetx->del("couple");
			(CChar *)targetx->add("couple_betray",1);
			targetx->Save();
			
			g_Channel.do_channel(me, NULL, "chat", "\n\n$HIW天下花痴出我辈，一入江湖岁月催，\n昔日红颜今何在？不胜人生一场醉！\n缘聚缘散，皆由天定，勉强不来啊。。。\n\n");
			g_Channel.do_channel(me, NULL, "news", snprintf(msg, 255, "$HIW\n\n%s轻轻含住了忘情石，玉石在瞬间即刻融化为一种液体，渗进%s的心中。\n前尘往事如云烟，再勿相逢再勿念，一缕红娘系过的红线节节断落。\n自此后，%s和%s割断夫妻名分，再无瓜葛。。。\n\n" ,me->querystr("name"),me->querystr("name"),me->querystr("name"),targetx->querystr("name")));
		}
	}
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



