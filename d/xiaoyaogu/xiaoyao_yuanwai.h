//xiaoyao_yuanwai.h 院外
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_yuanwai);

virtual void create()
{
	set_name( "院外");

	add_door("逍遥谷小院", "逍遥谷小院", "逍遥谷院外");	
	add_door("逍遥谷小路2", "逍遥谷小路2", "逍遥谷院外");	
	add_door("逍遥谷小路3", "逍遥谷小路3", "逍遥谷院外");	

};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu8_1") && me->query_temp("xy/renwu8_1") 
			&& !me->query("xy/renwu8_2") )
		{
			me->delete_temp("xy/renwu8_1");
			tell_object(me, "\n$HIC经过这几日的寻访，你仍然没有得到逍遥子的半点消息，心下记挂李秋痕的安危，便打算先回来看看情形。");
			tell_object(me, "$HIC忽然一声破空之声传来，一团白色之物快速地向你面门打来。");
			tell_object(me, "$HIC你随手一抄，便接住了那物，仔细一看，原来是一卷揉皱了的纸团。");
			tell_object(me, "$HIC打开一看，赫然竟是一张药单！\n");
			me->set("xy/renwu8_2",1);//得到恢复李秋痕容貌的药单
			load_item("xy_yaodan")->move(me);
		}
		else if(me->query("xy/renwu3") && me->query_temp("xy/renwu3_4") 
			 && !me->query_temp("xy/renwu3_5")&& !me->query_temp("xy/tanhuan4"))
		{
			//检查逍遥子是否在院外，如没有这个NPC则变一个
			CContainer * env = load_room("逍遥谷院外");
			CContainer * xiaoyaozi=env->present("xiaoyao zi");
			if(!xiaoyaozi)
			{
				CChar * XyNpc = load_npc("xy_xiaoyaozi");
				XyNpc->move(load_room("逍遥谷院外"));
			}
			me->disable_player("毒发中");
			me->call_out(do_tanhua, 1);
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(me->query_temp("xy/tanhuan4"))
	{
	case 0:
		tell_object(me, "\n逍遥女交给逍遥子一朵$HIY紫天雪莲$COM。");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "逍遥子将$HIY紫天雪莲$COM的花瓣尽数摘下，放入一个木碗中，然后从怀中取出一只小药瓶，向木碗中洒了一些药粉。");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, "不一会儿，花瓣便溶成了一碗浅紫色的$HIY雪莲汁$COM。");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "逍遥子喂你服下一碗$HIY紫天雪莲汁$COM，然后双手贴于你的背上为你引气推宫，以催动药力，解除顽毒。");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "你只觉脉门上一热，一股内力自手臂上升，迅速无比的冲向心口。");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "这股内力越来越大，来的越来越猛，直攻你周身诸穴，你感觉整个身体就像快要爆开一样，痛苦难当。");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, "忽然你喉头一甜，一口鲜血狂吐而出，眼前一黑，晕厥过去。");
		me->delete_temp("xy/tanhuan4");
		if(me->query_temp("xy/renwu3_0"))
			me->delete_temp("xy/renwu3_0");
		me->set_temp("xy/renwu3_5",1);//解除了所中的蜘蛛毒
		me->enable_player();
		me->apply_condition("scorpion_poison", 0);
		me->unconcious();
		me->set("hp",me->query("eff_hp"));
		me->move(load_room("逍遥谷小屋"));
		//检查逍遥女是否在房间，如有这个NPC则销毁
		env = load_room("逍遥谷院外");
		CContainer * xiaoyaonv=env->present("xiao yao nv");
		if(xiaoyaonv)
		{
			destruct(xiaoyaonv);
		}
		//检查逍遥子是否在房间，如有这个NPC则销毁
		CContainer * xiaoyaozi=env->present("xiaoyao zi");
		if(xiaoyaozi)
		{
			destruct(xiaoyaozi);
		}
		break;
	}
}
XiaoYao_END;
