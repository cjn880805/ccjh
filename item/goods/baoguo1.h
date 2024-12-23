ITEM_BEGIN(CIbaoguo1);

virtual void create(int nFlag = 0)		
{
	set_name("大红包裹","bao guo");	
	set_weight(20000);
};

virtual int do_look(CChar * me)
{
	say("一个用大红布包着的包裹，不知道里面装的是什么。", me);
	SendMenu(me);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		if(querystr("owner")[0])
		{
			if(EQUALSTR(querystr("owner"), me->id(1)))
			{
				if(me->query("xkd/wei")==500)
				{
					load_item("tiancanbaojia")->move(me);
					tell_object(me,"包裹包装得很不断严实，你好不容易才打开包裹，发现里面装的居然是一件天蚕宝甲");
					me->del("xkd/wei");
				}
				else if(me->query("xkd/wei")==200)
				{
					load_item("xuantiebishou")->move(me);
					tell_object(me,"你打开包裹，发现里面装的是一把削铁如泥的玄铁匕首。");
				}
				else if(me->query("xkd/wei")==50)
				{
					load_item("38huoqiang")->move(me);
					tell_object(me,"你打开包裹，发现里面装了一把精致的点三八火枪。");
				}
				else
				{
					char msg[255];
					if(random(2))
					{
						me->add("combat_exp",3000+me->query("xkd/wei")*50);
						me->UpdateMe();
						tell_object(me,snprintf(msg, 255,"你打开了包裹，发现了一些行走江湖的心得，从中领悟到了%d点经验！。\n",3000+me->query("xkx/wei")*100));
					}
					else
					{
						CContainer * bot = load_item("yinpiao1");
						bot->set("value", 200000+me->query("xkd/wei")*100);
						bot->move(me);
						tell_object(me,snprintf(msg, 255,"你打开层层包裹，却发现里面装的是一张%d两的银票！",200000+me->query("xkx/wei")*1000));
					}
				}
			}
		}
		destruct(this);
		return 1;
	}

	return notify_fail("包裹不能对别人使用。");
}

ITEM_END;

