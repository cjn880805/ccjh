//xiaoyao_baihu17.h 白虎塔塔底
//秦波 2002、12、17

XiaoYao_BEGIN(CRXiaoYao_baihu17);

virtual void create()
{
	set_name( "白虎塔塔底");
	
	add_door("白虎塔塔底6", "逍遥谷白虎塔塔底16", "逍遥谷白虎塔塔底17");
	add_door("白虎塔二层", "逍遥谷白虎塔二层21", "逍遥谷白虎塔塔底17");
	
	add_npc("xy_baihu1");
	add_npc("xy_baihu1");
	
};


virtual int do_look(CChar * me)
{
	if(me->query_temp("xy/ta/白虎/2")!=query("count") )
	{
		say("一扇厚厚的石门挡住了去路，看样子是由什么机关控制其开合。由于塔内年久失修，石门已不再严实，看起来只要稍用些力气便可以推开了。", me);
		say("但若是直接推开石门前进，也不知是否会碰到一些可怕的陷井，所以最好还是回去找找有没有解开机关的办法。", me);
		AddMenuItem("推开石门", "$0tuei $1", me);
		AddMenuItem("再想想办法", "", me);
		SendMenu(me);
	}
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (me->query_temp("xy/renwu4_1")  && me->query("xy/renwu4_3"))
	{
		if(!strcmp(comm, "tuei") )
			return do_tuei(me, arg);
	}
	return 0;
}

int do_tuei(CChar *me, char * arg)
{
	if(me->query("mp")<1500)
		tell_object(me, "\n$YEL你运起全身真气，向石门用力推去，石门依然纹丝不动，似乎你的内力不够！。\n");
	else
	{
		tell_object(me, "\n$YEL你运起全身真气，向石门用力推去，只听嘎嘎地一阵响，石门缓缓缩回了墙中。\n");
		char msg[255];
		int damage=me->query("hp")-random(500)-100;
		if(damage<0)
			damage=me->query("hp")-1;
		me->receive_damage("hp",damage);
		me->receive_wound("hp",damage);
		me->add("mp",-me->query("mp")*2/3);
		me->UpdateMe();
		switch(random(5))
		{
		case 0:
			tell_object(me, snprintf(msg, 255,"$HIR一排箭矢急射而过，你来不及躲避，结果受到了%d点的伤害。\n",damage));
			break;
		case 1:
			tell_object(me, snprintf(msg, 255,"$HIR忽然间，墙中射出满天的暗器，你躲无可躲，结果受到了%d的伤害。\n",damage));
			break;
		case 2:
			tell_object(me, snprintf(msg, 255,"$HIR地底忽地冒出一团烈焰，你被炽热的火焰包围，结果受到了%d的伤害。\n",damage));
			break;
		case 3:
			tell_object(me, snprintf(msg, 255,"$HIR一块大石呼啸着压下，你急忙闪向一边，但仍被擦伤多处，结果受到了%d的伤害。。\n",damage));
			break;
		case 4:
			tell_object(me, snprintf(msg, 255,"$HIR一瓢绿水当头淋下，你只觉得被绿水滴中之处巨痛难忍，就好似裂开来般，结果受到了%d的伤害。\n",damage));
			break;
		}
		me->move(load_room("逍遥谷白虎塔二层21"));
		if(me->query_temp("xy/renwu4_1"))
		{
			CContainer * XyNpc;
			if(me->query_temp("xy/renwu4_1")==1)
			{
				XyNpc=present("tong lao");
			}
			else
			{
				XyNpc=present("li qiou heng");
			}
			if(XyNpc)
			{
				if(XyNpc->query("owner")==atoi(me->id(1)))
					XyNpc->move(load_room("逍遥谷白虎塔二层21"));
			}
		}
	}
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4_3"))
		{
			me->move(load_room("佛山北帝庙"));
			return 0;
		}
		else if(!me->query_temp("xy/renwu4_1"))
		{
			tell_object(me, "\n$HIR通道深处漆黑一片，里面还不时传出一些奇异的声音，只吓得你心惊胆寒，不敢再近前一步！看来还是得请师伯或者师叔出马，来为你壮壮胆！\n");
			me->move(load_room("逍遥谷空地"));
			return 0;
		}
		CContainer * ShouWei=present("jiouwei hu");
		if(ShouWei)
		{
			tell_object(me, "$HIR白虎守卫大喝道，“大胆狂徒，竟敢乱闯白虎宝塔，还不快快与我退下？”");
			return 0;
		}
		if(me->query_temp("xy/ta/白虎/2")!=query("count") && EQUALSTR(dir,"白虎塔二层"))
		{
			tell_object(me, "$HIR一扇厚厚的石门挡住了去路，看样子是由什么机关控制其开合。");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
