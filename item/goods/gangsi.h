ITEM_BEGIN(CIgangsi);

virtual void create(int nFlag = 0)		
{
	set_name( "钢丝");	
	set("no_get", "钢丝你也想拿走？……你也太过分了吧。");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("这是一跟横贯幽兰涧两岸的细长钢丝，宽不足两指，长逾数丈，偶尔还随风摆荡。", me);
	say("钢丝下就是岩石峭壁与湍急的溪流。你看看旁边太监，他的眼神告诉你似乎要去内书房就必须经此而过。", me);
	if(me->query("lj/renwu11"))
	{
		say("看起来只有跳上（jump）钢丝，凭自己的本事才能走到涧的对岸。", me);
		AddMenuItem("跳上钢丝", "$9jump $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "jump") == 0)
		return do_jump(me, arg);
	return 0;
}

int do_jump(CChar *me, char * arg)
{
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;
	CContainer * env;
	int jump;
	while(p)
	{
		obj = list->GetNext(p);
		if(userp(obj) || EQUALSTR(obj->querystr("id"), "fight_room"))
		{
			me->move(load_room("佛山北帝庙"));
			return 1;
		}
	}
	if(!me->query("lj/renwu11") && !me->query("lj/renwu_大结局"))
	{
		message_vision("$HIR皇宫卫士伸手拦住了你，“大胆狂徒，皇宫也是你可以乱闯的地方？”", me);
		return 0;
	}
	else if(EQUALSTR(me->querystr("gender"), "女性") )
	{
		if(DIFFERSTR(me->querystr_temp("apply/name"),"竹虚"))
		{
			message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你是女人，何必来参加比武招亲呢？！”", me);
			return 0;
		}
		else if(!me->query_temp("lj/renwu111"))
		{
			message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你的易容术未免有点浅薄了……”", me);
			return 0;
		}
		else
		{
			int lvl=me->query_skill("dodge",1);
			if(lvl>=300)
				jump=1;
			else if(lvl>=200 )
			{
				if(random(100)>20)	jump=1;
			}
			else if(lvl>=100 )
			{
				if(random(100)>30)	jump=1;
			}
			else if(lvl>=50 )
			{
				if(random(100)>50)	jump=1;
			}
			if(jump==1 || me->query("lj/renwu_大结局"))
			{
				tell_object(me, "\n$HIR你纵身一跃，跳上钢丝，身形晃了几晃，勉强支持住没有掉下涧去。 "); 
				me->add_temp("lj/renwu118",1); //设置第一次跳过钢丝后奖励5000点经验的奖励标志
				env = me->environment();
				if(EQUALSTR(env->querystr("name"), "幽兰涧"))
					me->move(load_room("灵州皇宫幽兰涧东"));
				else
					me->move(load_room("灵州皇宫幽兰涧"));
				if(me->query_temp("lj/renwu118")==1)
				{
					me->add("combat_exp",5000);
					me->UpdateMe();
					tell_object(me, "\n$HIR你通过了“西夏皇宫比武招亲中轻功项目”的考验，获得了5000点的经验奖励。\n");
				}
			}
			else
			{
				tell_object(me, "\n$HIR你身形一跃，足踏钢丝，却不料失去平衡，自半空中摔下，还好并无大碍。 "); 
				tell_object(me, "$HIR你失去了招亲资格！"); 
				tell_object(me, "\n\n$HIR你参加比武招亲失败，无缘见得西夏公主，亦无法求证梦姑在宫内何处，长叹之下只有放弃 ！\n\n"); 
				me->del("lj");
				me->delete_temp("lj");
				env = load_room("灵州皇宫大门");
				if(env->query("start"))env->del("start");
				env = load_room("灵州皇宫大厅");
				if(env->query("start"))env->del("start");
				me->move(load_room("灵州皇宫大门"));
			}
		}
	}
	else
		tell_object(me,"$HIR我昏！你是怎么混到这里来的呢？有人出老千呀！");
	return 1;
}

ITEM_END;

