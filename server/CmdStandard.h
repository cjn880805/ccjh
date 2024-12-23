
void wakeup1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	if(!me) return;

	me->set("hp", me->query("eff_hp"));
	if (me->query("mp") < me->query("max_mp"))
		me->set("mp", me->query("max_mp"));

	me->enable_player();

	while( (me->environment())->is_character() )
		me->move((me->environment())->environment());

    message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。", me);
	me->delete_temp("block_msg/all");
	tell_object(me, "你一觉醒来，只觉精力充沛。该活动一下了。");	
	me->FlushMyInfo();
}

class CCmdStandard
{
public:
	CCmdStandard()
	{
		m_StandardCmd["kill"] = Kill;
//		m_StandardCmd["hit"] = Hit;
		m_StandardCmd["cast"] = Cast;
		m_StandardCmd["join"] = JoinBattle;
		m_StandardCmd["guard"] = Guard;		//观战
		m_StandardCmd["fight"] = Fight;
		m_StandardCmd["follow"] = Follow;
		m_StandardCmd["halt"] = Halt;
		m_StandardCmd["flee"] = Halt;

		m_StandardCmd["tell"] = Tell;
		m_StandardCmd["say"] = Say;

		m_StandardCmd["get"] = Get;
		m_StandardCmd["drop"] = Drop;
		m_StandardCmd["wield"] = Wield;
		m_StandardCmd["unwield"] = UnWield;
		m_StandardCmd["use"] = Use;
		m_StandardCmd["go"] = GoDoor;
		m_StandardCmd["give"] = Give;

		m_StandardCmd["apprentice"] = Apprentice;
		m_StandardCmd["recruit"] = Recruit;
		m_StandardCmd["expell"] = Expell;
		m_StandardCmd["learn"] = Learn;
		m_StandardCmd["teach"] = Teach;

		m_StandardCmd["sleep"] = Sleep;
		m_StandardCmd["exercise"] = Exercise;
		m_StandardCmd["enable"] = Enable;
		m_StandardCmd["study"] = Study;
		m_StandardCmd["practice"] = Practice;		//不允许玩家练习
		m_StandardCmd["prepare"] = Prepare;
		m_StandardCmd["abandon"] = Abandon;
		m_StandardCmd["enforce"] = Enforce;
		m_StandardCmd["look"] = Look;

		m_StandardCmd["wench"] = wench;
		m_StandardCmd["makelove"] = MakeLove;
	};

	~CCmdStandard(){};

	int Handlecommand(char * cmd, CChar * me, LONG target, char * arg)
	{
		CMDMAP::iterator p;
		if((p = m_StandardCmd.find(cmd)) == m_StandardCmd.end()) return -1;
		return ((*p).second)(me, target, arg);
	}

	//拾取 get sth. from sth. num
	DEFINECMD(Get)
	{
		char cmd[255], szEnv[40], szNum[40];
		CContainer * who, * env, * obj = NULL;
		LONG num = 0;
		int ap = 30;
		CMapping * m;

		if( me->is_busy() )
			return notify_fail("你上一个动作还没有完成！");

		env = me->environment();
		if(strlen(arg))
		{
			analyse_string(arg, szEnv, 40);
			analyse_string(szEnv, szNum, 40);
			if(atol(szEnv)) env = env->Present(atol(szEnv));
			num = atol(szNum);
		};

		if(!env || EQUALSTR(env->querystr("status"), "locked")) return 0;
		if(env->Query(CChar::IS_FIGHTROOM) && ! me->is_fighting() && ! wizardp(me))
			return notify_fail("你想拣战场里的东西，但是太危险了，你犹豫了一下，又退缩了。");

		if(living(env) && (me->query("grant") < 70 || wiz_level(me) <= wiz_level((CChar *)env) ))
			return notify_fail("你的巫师等级必须比对方高，才能搜身。");

		who = env->Present(target);

		if( ! CheckAP(ap, me))
			return 0;

		if(! who || ! who->Query(CChar::CAN_GET))
			return notify_fail("你要拣什么。");

		m = who->query_entire_dbase();
		if(! m->undefinedp("no_get") && !(wizardp(me) && me->query("env/override")) )
		{
			strncpy(cmd, who->querystr("no_get"), 255);
			return notify_fail(cmd[0] ? cmd : "这个东西拿不起来。");
		}

		//判断是否主人
		if( ! m->undefinedp("owner") && !(wizardp(me) && me->query("env/override"))
			&& DIFFERSTR(who->querystr("owner"), me->querystr("id")) )
			return notify_fail("这不是你的东西。");

		if(num && who->Query(CChar::IS_ITEM) )
		{
			obj = ((CItem *)who)->Split(num);
		}
	
		if(! obj)
		{
			obj = who;
			num = who->Query_Amount();
		}
		
		snprintf(cmd, 255, "%s拾起数量%ld的%s。", me->name(), 
			num, obj->name(), env->name());
		
		if( obj->move(me))
			MessageVision(me, "chat", cmd);
		else
		{
			notify_fail("此物你无法负担。");
			if(obj != who) 
			{
				DESTRUCT_OB(obj, "cmd::get");
				((CItem *)who)->add_amount(num);
			}

			return 0;
		}

		ResumeAP(ap, me);

		if(me->is_fighting()) me->start_busy(2);
		return 1;
	}

	//使用物品
	DEFINECMD(Use)
	{
		CContainer * who;
		CContainer * obj = me;

		//禁止在设置为no_use的场景使用use命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_use")||env->query("no_all"))&& userp(me) )
			return notify_fail("这里禁止使用道具。");

		char szTarget[40];
		
		if( me->is_busy() )
			return notify_fail("你上一个动作还没有完成！");

		int ap = 50;
		if(! (who = GetSelfObject(me, target)) ) return 0;

		if(strlen(arg))
		{
			analyse_string(arg, szTarget, 40);
			if( ! (obj = GetRoomObject(me, atol(szTarget)) )
				&& ! (obj = GetSelfObject(me, atol(szTarget)) ) )
				return notify_fail("你要对谁使用？");
		}
	
		if( who->Query(CChar::CAN_USE) && CheckAP(ap, me))
		{
			CContainer * item = who;
			LONG amount = who->Query_Amount();
			if(amount > 1)
				item = ((CItem *)who)->Split(1);

			LONG objectid = item->object_id();

			if( ((CItem *)item)->do_use(me, obj))
			{
				ResumeAP(ap, me);

				if(g_LastDestructObject != objectid && who != item)
				{					
					DESTRUCT_OB(item, "cmd::use");					
					who->set_amount(amount);
				}	
				
				if(me->is_fighting()) me->start_busy(2);
				return 1;
			}
			
			if(who != item)
			{
				DESTRUCT_OB(item, "cmd::use");
				who->set_amount(amount);
			}
		}
	
		return 0;
	}

	//装备
	DEFINECMD(Wield)
	{
		char cmd[80];
		int ap = 25;
		CContainer * who;

		if( ! (who = GetSelfObject(me, target)) ) return 0;

		//禁止在设置为no_wield的场景使用wield命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_wield")||env->query("no_all"))&& userp(me))
			return notify_fail("这里禁止装备道具。");

		if(me->is_busy())
			return notify_fail("你正忙着");

		notify_fail("你无法装备这样东西。");
		if(who->Query(CChar::CAN_EQUIPPED) && CheckAP(ap, me) && who->Do_Action(CChar::DO_WIELD))
		{
			strncpy(cmd, who->querystr("wield_msg"), 80);
			if(! strlen(cmd))
			{
				strncpy(cmd, who->querystr("wear_msg"), 80);
				if( ! strlen(cmd))
					strcpy(cmd, "$N装备$n。");
			}

			message_vision(cmd, me, who);
			ResumeAP(ap, me);
			me->FlushMyEquip();
			me->FlushMyInfo();

			if(me->is_fighting()) me->start_busy(2);
			return 1;
		}

		return 0;
	}

	//卸下
	DEFINECMD(UnWield)
	{
		char cmd[80];
		int ap = 25;
		CContainer * who;

		//禁止在设置为no_unwield的场景使用unwield命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_unwield")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止卸下道具。");

		if(me->is_busy())
			return notify_fail("你正忙着。");

		if( strcmp(arg, "all") == 0)	//无参数表示全部卸下
		{
			DTItemList search;
			POSITION p;
			CContainer * obj;

			CopyList(&search, me->Get_ItemList());
			p = search.GetHeadPosition();
			while(p)
			{
				obj = search.GetNext(p);
				if(CheckAP(ap, me) && obj->Do_Action(CChar::DO_UNWIELD))
				{
					strncpy(cmd, obj->querystr("unwield_msg"), 80);
					if(! strlen(cmd))
						strcpy(cmd,  "$N放下手中的$n。");
					message_vision(cmd, me, obj);
					ResumeAP(ap, me);
				}
			}
			me->FlushMyEquip();
			me->FlushMyInfo();

			if(me->is_fighting()) me->start_busy(2);
			return 1;
		}

		if(! (who = GetSelfObject(me, target)) ) return 0;
		if(CheckAP(ap, me) && who->Do_Action(CChar::DO_UNWIELD))
		{
			strncpy(cmd, who->querystr("unwield_msg"), 80);
			if(! strlen(cmd))
			{
				strncpy(cmd, who->querystr("remove_msg"), 80);
				if(! strlen(cmd))
					strcpy(cmd,  "$N放下手中的$n。");
			}

			message_vision(cmd, me, who);
			ResumeAP(ap, me);
			me->FlushMyEquip();
			me->FlushMyInfo();

			if(me->is_fighting()) me->start_busy(2);
			return 1;
		}
		return 0;
	}

	static int do_drop(CChar * me, CContainer * obj, CContainer * env, LONG x, LONG y)
	{
		char msg[255];

		//定位
		obj->set_temp("map/bx", x);
		obj->set_temp("map/by", y);
		obj->set_temp("map/ex", x);
		obj->set_temp("map/ey", y);
		obj->set_temp("map/ac", 0l);

		LONG amount = obj->Query_Amount();
		if (obj->move(env)) 
		{
			if( obj->is_character() )
			{
				message_vision(snprintf(msg, 255, "$N将$n从背上放了下来，躺在%s里。", env->name()), me, obj);				
			}
			else 
			{
				message_vision( snprintf(msg, 255, "$N向%s里丢下数量%ld的$n。", env->name(), amount ), me, obj );
				if( ! obj->query("value") ) 
				{
					tell_object(me, "因为这样东西并不值钱，所以人们并不会注意到它的存在。");
					DESTRUCT_OB(obj, "cmd::drop");
				}
			}
			return 1;
		}
		return 0;
	}

	//丢弃物品 drop x y sth. to sth. num
	DEFINECMD(Drop)
	{
		CContainer * env, * who;
		char szTo[80], szY[80], szEnv[40], szNum[20];
		int ap = 30;
		LONG nNum = 0;
		LONG x = 0, y = 0;
		CContainer * obj = 0;
		CMapping * m;

		env = me->environment();

		//禁止在设置为no_drop的场景使用Drop命令 秦波 2002-10-09
		if((env->query("no_drop")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止丢弃物品。");
	
		if(strlen(arg))
		{
			analyse_string(arg, szY, 80);
			analyse_string(szY, szTo, 80);
			analyse_string(szTo, szEnv, 40);
			analyse_string(szEnv, szNum, 20);

			if(atol(szEnv)) env = env->Present(atol(szEnv));
			nNum = atol(szNum);		

			x = atol(arg);
			y = atol(szY);
		}
	
		if(! env || EQUALSTR(env->querystr("status"), "locked") ) return 0;

		if(! (who = GetSelfObject(me, target)) ) return 0;

		if(! x || ! y)	//无坐标，得丢弃者的目的坐标
		{
			x = me->query_temp("map/ex");
			y = me->query_temp("map/ey");
		}

		m = who->query_entire_dbase();
		if(! m->undefinedp("no_drop"))
		{
			const char * ptr = m->querystr("no_drop");
			return notify_fail(ptr[0] ? ptr : "这样东西不能随意丢弃。");
		}

		if(me->is_busy())
			return notify_fail("你正忙着。");

		//判断房间里是否还能容纳
		DTItemList * list = env->Get_ItemList();
		if(list->GetCount() >= env->query("max_items"))
			return notify_fail("%s里已经够拥挤了。", env->name());

		if(! CheckAP(ap, me)) return 0;

		if(! nNum) nNum = 1;
		if( who->Query(CChar::IS_ITEM) )
		{
			obj = ((CItem *)who)->Split(nNum);
		}

		if(! obj) obj = who;

		if( obj->is_character() )
		{
			if(env->query("no_drop_man")&&!wizardp(me))
				return notify_fail("空间太小，此物无法容纳。");
		}

		if(! do_drop(me, obj, env, x, y))
		{
			//把东西再还给本人。
			if(obj->environment() != me)
				obj->move(me);
			return 0;
		}			

		ResumeAP(ap, me);
		return 1;
	}

	static int valid_move(CChar * me)
	{
        if( me->over_encumbranced() )
            return notify_fail("你的负荷过重，动弹不得。");

        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。");

        if( me->query_temp("no_move") )
                return notify_fail("你现在不能移动！");

        return 1;
	}

	//进门
	DEFINECMD(GoDoor)
	{
		CContainer * env = me->environment();//, *obj;
		CDoor * door;
		char msg[255];

		if(! valid_move(me)) return 0;

		notify_fail("你要往哪个方向走？");
		if(! env->Query(CChar::IS_ROOM)) return 0;
	
		//如果是宠物，判断一下主人是否在一个房间。如果主人在则转嫁给主人。
		me = FindMaster(me);
	
		door = ((CRoom *)env)->PresentDoor(arg);
		if(! door) return 0;

		if( !((CRoom *)env)->valid_leave(me, door->querystr("id")) ) return 0;

		if(door->Enter_Door(me) )
		{
			snprintf(msg, 255, "%s往%s离开。", me->name(), door->name(1) );
			MessageVision(env, "room", msg);

			snprintf(msg, 255, "%s走了过来。", me->name());
			MessageVision(me, "chat", msg, me);

			me->delete_temp("pending");

			//旧环境内的物件跟随
			POSITION p;
			DTItemList search;
			CContainer * obj;
					
			CopyList(&search, env->Get_ItemList());
				
			p = search.GetHeadPosition();
			while(p)
			{
				obj = search.GetNext(p);
				if(! living(obj)) continue;
				if(obj == me) continue;
				if(obj->environment() != env) continue;	//已经移动
				((CChar *)obj)->follow_me(me, arg);
			}

			search.RemoveAll();
			return 1;
		}

		return 0;
	}

	static int Do_Give(CChar * me, CContainer * obj, CChar * who)
	{
		char cmd[255];

		if(who->query("env/no_accept"))
			return notify_fail("对方好象不愿意收下你的东西。");

		LONG objid = obj->object_id();
		snprintf(cmd, 255, "$N给$n数量%ld的%s。", obj->Query_Amount(), obj->name());

		if(who->Query(CChar::IS_NPC) && ! who->Query(CChar::IS_SPRITE))
		{
			if(! ((CNpc *)who)->accept_object(me, obj) ) 
			{
				return notify_fail("对方不要你的东西。");
			}
		}

		message_vision(cmd, me, who);

		if(g_LastDestructObject == objid)	//已经被销毁
		{
			me->Save();
			return 1;
		}
			
		/*if( !userp(who) && obj->query("value")) //NPC 不想把东西留着，就在ACCEPT里直接把物件销毁。
		{
			destruct(obj);
			me->Save();
			return 1;
		}
		else*/
		if( obj->move(who) ) 
		{
			me->Save();				
			return 1;
		}

		return 0;
	}

	//给 give sth. to sb. num
	DEFINECMD(Give)
	{
		CContainer * env, * who;
		CChar * Target; 
		char szTarget[40], szNum[20];
		int ap = 30;
		LONG nNum = 0;
		CContainer * obj = 0;
		
		if(! (env = me->environment()) ) return 0;
		if(! strlen(arg)) return 0;
	
		analyse_string(arg, szTarget, 40);
		analyse_string(szTarget, szNum, 20);

		if( ! (Target = GetRoomChar(me, atol(szTarget)) ) || Target == me) return 0;
		nNum = atol(szNum);

		if(me->is_busy())	return notify_fail("你正忙着。");

		if(! living(Target)) return notify_fail("对方没办法接受你的礼物。");
		
		if(! CheckAP(ap, me)) return 0;

		if(! nNum) nNum = 1;
	
		if( ! (who = GetSelfObject(me, target)) ) return 0;

		if( who->Query(CChar::IS_USER))
			 return notify_fail("送人？你有何居心？");

		CMapping * m = who->query_entire_dbase();
		if(! m->undefinedp("no_give") && !(wizardp(me) && me->query("env/override")))
		{
			const char * ptr = m->querystr("no_give");
			return notify_fail(ptr[0] ? ptr : "这样东西不能随意给人。");
		}

		if(! m->undefinedp("no_drop") && !(wizardp(me) && me->query("env/override")))
			return notify_fail("这样东西不能随便给人。");

		//判断是否主人
		if( ! m->undefinedp("owner") && !(wizardp(me) && me->query("env/override"))
			&& DIFFERSTR(who->querystr("owner"), Target->querystr("id")))
			return notify_fail("这不是%s的东西。", Target->name(1));

		if( ! m->undefinedp("obj") && !(wizardp(me) && me->query("env/override"))
			&& DIFFERSTR(who->querystr("obj"), Target->querystr("id")))
			return notify_fail("这不是%s的东西。", Target->name(1));
	
		if( who->Query(CChar::IS_ITEM) )
		{
			obj = ((CItem *)who)->Split(nNum);			
		}

		if(! obj) obj = who;
		if(! Do_Give(me, obj, Target))
		{
			//把东西再还给本人。
			if(obj->environment() != me)
				obj->move(me);
			return 0;
		}
	
		ResumeAP(ap, me);
		return 1;
	}

	//拜师
	DEFINECMD(Apprentice)
	{
		CChar * who;
		char msg[255];

		if(! (who = GetRoomChar(me, target))) return 0;

		//禁止在设置为no_apprentice的场景使用Apprentice命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_apprentice")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止拜师。");

		me = FindMaster(me);
		who = FindMaster(who);

		if( ! who->Query(CChar::IS_LIVING) )
		{
			return notify_fail("你必须先把%s弄醒。", who->name());
		}

		if( who==me ) 
			return notify_fail("拜自己为师？好主意．．：P");
	
		if( me->is_apprentice_of(who) ) 
		{
			message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」", me, who);
			return 1;
		}

		const char * bangpai = me->querystr("family/family_name");
		if ( bangpai[0] && DIFFERSTR(bangpai, who->querystr("family/family_name")) )
			return notify_fail("未经本派师门同意不能改换门派！");
		
		if (EQUALSTR(who->querystr("family/master_id"), me->querystr("id")))
			return notify_fail("开什么玩笑？拜自己的徒弟为师？");
			
		// If the target is willing to recruit us already, we do it.
		if( who->query_temp("pending/recruit") == me->object_id()) 
		{
			if( EQUALSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
			{
				message_vision("$N决定投入$n门下！！$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」", me, who);
				me->set("score", 0L);
			} 
			else
				message_vision("$N决定拜$n为师。$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」", me, who);
				    
			who->recruit_apprentice(me);
			who->delete_temp("pending/recruit");

			tell_object(who, "恭喜你新收了一名弟子！");
			tell_object(me, snprintf(msg, 255, "恭喜您成为%s的第%ld代弟子。",  me->querystr("family/family_name"), me->query("family/generation")));
				
			return 1;
   		} 

		tell_object(me, snprintf(msg, 255, "你想要拜%s为师。",	who->name()) );
		me->set_temp("pending/apprentice", who->object_id());
		if( who->Query(CChar::IS_USER))
		{
			tell_object(who, snprintf(msg, 255, "如果你愿意收%s为弟子，请与其交谈。", me->name()));
			
			//改为菜单发送。 1.7版 lanwood 2001-03-24
			//注意，不能用$1来代替me，因为对方未必选中你为当前目标。
			/*
			char tmp[40];

			me->AddMenuItem(snprintf(msg, 80, "收%s为徒", me->name()), 
				snprintf(tmp, 40, "$0recruit %ld", me->object_id()), who);
			me->AddMenuItem("离开", "", who);
			me->SendMenu(who);
			*/
		}
		else 
			who->attempt_apprentice(me);
   
		return 1;
	}

	//收徒
	DEFINECMD(Recruit)
	{
		char msg[255];
		CChar * who;

		if(! (who = GetRoomChar(me, target))) return 0;

		//禁止在设置为no_recruit的场景使用Recruit命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_recruit")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止收徒。");

		me = FindMaster(me);
		who = FindMaster(who);

		if( who == me )
			return notify_fail("收自己为弟子？好主意．．．不过没有用。");

		if( who->is_apprentice_of(me) )
		{
			message_vision("$N拍拍$n的头，说道：「好徒儿！」", me, who);
			return 1;
		}


		if(! me->querystr("family/family_name")[0])
			return notify_fail("你并不属于任何帮派，你必须先加入一个帮派，或自己创一个才能收徒。");
		
		if(! me->query("family/generation"))
			return notify_fail("你乃弃徒，先求哪一位本门师父将你重列门墙再说吧。");
		
		const char * bangpai = who->querystr("family/family_name");
		if ( bangpai[0] && DIFFERSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
			return notify_fail("未经其师尊同意就挖人家墙角不太好吧。");
		
		if ( EQUALSTR(me->querystr("family/master_id"), who->querystr("id")) )
			return notify_fail("开什么玩笑？人家是你师父，还有什么要从你这里学的？");
	
		//begin----- 玩家收徒的限制 lanwood 2001-02-25

		//在申请掌门的时候，会自动设置掌门经验为50
		int count = 0;
		if(userp(me) && (count = me->recruit_num()) >= me->query("recruit_exp") / 50) 
			return notify_fail("你已有徒弟%ld人。以你的掌门经验不能再收徒！", count);
		
		//end-------

		// If the target is willing to apprentice us already, we do it.
		if( who->query_temp("pending/apprentice") == me->object_id())
		{
			if(! who->Query(CChar::IS_LIVING))
			{
				message_vision("$N决定收$n为弟子。不过看样子$n显然没有办法行拜师之礼。", me, who);
				return 1;
			}
        
			// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
			if(who->querystr("family/family_name")[0] && DIFFERSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
			{
				message_vision("$N决定投入$n门下！！\n$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」", me, who);
				who->set("score", 0L);
			} 
			else
			{
				message_vision("$N决定收$n为弟子。\n$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」", me, who);          
			}
		
			me->recruit_apprentice(who);
			who->delete_temp("pending/apprentice");

			tell_object(me, "恭喜你新收了一名弟子！");
			tell_object(who, snprintf(msg, 255, "恭喜您成为%s的第%ld代弟子。", who->querystr("family/family_name"), who->query("family/generation")) );
			return 1;
		} 

		me->set_temp("pending/recruit", who->object_id());
		message_vision("$N想要收$n为弟子。", me, who);
		
		tell_object(who, snprintf(msg, 255, "如果你愿意拜%s为师父，请与其交谈。", me->name()));
		
		/*//改为菜单指令。1。7版 lanwood 2001-03-24
		char tmp[40];

		me->AddMenuItem(snprintf(msg, 255, "拜%s为师", me->name()), 
			snprintf(tmp, 40, "$0apprentice %ld", me->object_id()), who);
		me->AddMenuItem("离开", "", who);
		me->SendMenu(who);
		*/

		return 1;
	}

	//逐出师门
	DEFINECMD(Expell)
	{
		char msg[255];
		CChar * who;

		if(! (who = GetRoomChar(me, target))) return 0;

		//禁止在设置为no_expell的场景使用Expell命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_expell")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止弃徒。");

		if( ! who->Query(CChar::IS_USER))
			return notify_fail("你只能开革玩家所扮演的人物。");

		if( me->query("family/privs") == -1
			&&  EQUALSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
		{
			message_vision(snprintf(msg, 255, "$N对着$n说道：从今天起，你再也不是我%s的弟子了，你走吧！", me->querystr("family/family_name")), me, who);
			tell_object(who, "你被开革出师门了！");
		} 
		else if( (who)->is_apprentice_of(me) ) 
		{
			message_vision("$N对着$n说道：从今天起，你我师徒恩断情绝，你走吧！江湖风波，善恶无形，好自为之。。。", me, who);
			tell_object(who, "你被师父开革出师门了！");
		} 
		else
			return notify_fail("这个人不是你的弟子。");
	
		char myfamily[80];
		who->release_master();

		me->del("zhangmen");
		who->del("family");
		snprintf(myfamily, 80, "%s弃徒", who->querystr("family/family_name"));
		who->set("title", myfamily);
		who->UpdateMe();
		who->Save();

		CMapping * skills = who->query_skills();
		
		CVector v;

		skills->keys(v);
		//所有技能降一半
		for(int i=0; i<v.count(); i++)
		{
			(*skills)[v[i]] /= 2;
		}
	
		return 1;
	}

	DEFINECMD(Teach)
	{
		
		//禁止在设置为no_teach的场景使用Teach命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_teach")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止传授技能。");

		CChar * who;

		if (me->is_busy())
			return notify_fail("你现在正忙着呢。");
		
		if( me->is_fighting() )
			return notify_fail("临阵磨枪？来不及啦。");

		if(! me->querymap("couple")) 
			return notify_fail("你还没有伴侣呢！");

		who = (CChar *)(me->environment())->present(me->querystr("couple/id"));

		 if( !who ) 
			 return notify_fail("你的%s不在这里。", me->querystr("couple/gender"));			
		
		if( !living(who) )
			return notify_fail("嗯....你得先把%s弄醒再说。", who->name());

		if(who->is_busy())
			return notify_fail("%s现在正忙着呢。", who->name());

		if(who->is_fighting() )
			return notify_fail("临阵磨枪？来不及啦。");

		if(who && me->query("add_skill/count"))
			return notify_fail("你暂时无法指点你伴侣的武功。。");


		if(! strlen(arg))	//无参数，显示可以教的技能
		{
			CMapping * skills;
			CSkill * sk;
			char skill_name[80], cmd[80];

			skills = me->query_skills();

			int pt = who->query("level") * who->query_int() / 50;
			if(pt <= 0) pt = 1;
			
			CVector v;

			skills->keys(v);
			for(int i=0; i<v.count(); i++)
			{
				LONG need_points =  who->skill_need_points(v[i]);				
				
				sk = load_skill(v[i]);

				sprintf(skill_name, "%-20s %ld", sk->name(1), need_points / pt + 1);
				who->AddMenuItem(skill_name, snprintf(cmd, 80, "$0teach $1 %s", v[i]), me);
			}

			who->AddMenuItem("离开", "", me);
			who->SendMenu(me);

			return 1;
		}

		int my_skill = me->query_skill(arg, 1);

		if( ! my_skill )
			return notify_fail("这项技能你还不会呢！");

		int student_skill = who->query_skill(arg, 1);

		if( my_skill <= student_skill )
			return notify_fail("这项技能%s的程度已经不输于你了。", who->name());

		CSkill * sk = load_skill(arg);

		notify_fail("依%s目前的能力，没有办法学习这种技能。", who->name());
		if( ! sk->valid_learn(who) ) 
		   return 0;

		if(student_skill>351)
			return notify_fail("你的爱侣学习潜力已经发挥到头了，这项技能还是爱侣自己去江湖历练中领悟更高的境界吧。");

		//增加忘记技能判断 lanwood 2001-05-27
		if(! who->can_learn(arg)) return notify_fail("这项技能%s永世不得修习！", who->name());

		int gin_cost = 100;

		if( !student_skill ) 
		{
			gin_cost *= 2;
			who->set_skill(arg, 0);
		}

		if(me->query("sk_exp") * 3 > me->query("combat_exp"))
			return notify_fail("你已经没有多余的技能经验教你的爱侣了。");
		if(who->query("sk_exp") * 3 > who->query("combat_exp"))
			return notify_fail("你的爱侣学习潜力已经发挥到头了。还是帮助对方再历练历练吧。");
		
		//现在计算所需的经验
		LONG need_points =  who->skill_need_points(arg);
		LONG need_exp = need_points / who->learn_bonus() + 1;
		
		//计算玩家的经验够不够
		if(who->query_valid_exp() < need_exp)
			return notify_fail("学习%s还需%ld点经验，%s需要再历练历练。", sk->name(1), need_exp, who->name());
		if(me->query_valid_exp() < need_exp)
			return notify_fail("教会%s还需%ld点经验，你需要再历练历练。", sk->name(1), need_exp);
		
		char msg[255];

		tell_object(me, snprintf(msg, 255, "你向%s解释有关「%s」的疑问。", who->name(), sk->name(1)));

		if( who->query("env/no_learn") )
			return notify_fail("但是%s现在并不准备听你解释问题。", who->name());

		tell_object(who, snprintf(msg, 255, "%s向你解释有关「%s」的问题。", me->name(), sk->name(1)));

		if( me->query("hp") > gin_cost ) 
		{
			if( userp(me) ) me->receive_damage("hp", gin_cost );
		} 
		else 
		{
			tell_object(me, "但是你太累了，没有办法再教。");
			tell_object(who, snprintf(msg, 255, "但是%s显然太累了，没有办法教你什麽。", me->name()));
			return 1;
		}
			
		if(who->query("hp") > gin_cost )			
		{
			if( strcmp(sk->type(), "martial") == 0 && student_skill > CChar::level2skill(who->query("level")) ) 
			{
				tell_object(who, snprintf(msg, 255, "也许是缺乏实战经验，你对%s的解释总是无法领会。",  me->name()));
			}
			else
			{ 
				tell_object(who, snprintf(msg, 255, "你听了的指导，似乎有些心得。", me->name()));
             
   				who->add("sk_exp", need_exp);
				me->add("sk_exp", need_exp);

				who->improve_skill(arg, need_points + 1);				
			}

			who->receive_damage("hp", gin_cost);
		}
		else
		{
			tell_object(who, "你今天太累了，结果什么也没有学到。");
		}
		
		return 1;
	}

	//请教技能。
	/*
		Designed by Lanwood 2000-12-23

		师傅指点，一次一级。消耗100 HP
		需要经验：按到下一级所需learned计算。
		need_points = (skill + 1) * (skill + 1) - learned;
		一点经验可提高 pt = (level / 10 + 1) * int / 3;
		那么所需经验为：need_exp = need_points / pt + 1;
	*/

	DEFINECMD(Learn)
	{
		//禁止在设置为no_learn的场景使用Learn命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_learn")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止学习技能。");

		int master_skill, my_skill;
		CChar * who;
		char msg[255];
		
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。");

		if(! (who = GetRoomChar(me, target)))
			return notify_fail("你要向谁请教？");

		if(! strlen(arg)) return notify_fail("指令格式：learn skill_name");
	
		if( me->is_fighting() )
			return notify_fail("临阵磨枪？来不及啦。");

		if(! who->Query(CChar::IS_LIVING) )
			return notify_fail("嗯．．．你得先把对方弄醒再说。");

	//	if( !me->is_apprentice_of(who) )
	//		return notify_fail("对方显然不愿理你。");

		if( ! me->is_apprentice_of(who) && !(who->recognize_apprentice(me)) )
		{
			who->say("您见笑了，我这点雕虫小技怎够资格「指点」您什么？", me);
			who->SendMenu(me);
			return 0;
		}

		if( who->is_fighting())
			return notify_fail("你的师傅暂时没空指点你武功。");

		if( ! (master_skill = who->query_skill(arg, 1)) )
			return notify_fail("这项技能你恐怕必须找别人学了。");
	
		if( who->prevent_learn(me, arg) )
			return notify_fail("显然对方不愿教你这项技能。");

		if(who && who->query("add_skill/count"))
			return notify_fail("你的师傅暂时没空指点你武功。。");

		my_skill = me->query_skill(arg, 1);
	
		if( my_skill >= master_skill )
			return notify_fail("这项技能你的程度已经不输你师父了。");

		CSkill * sk = load_skill(arg);
		if(! sk) return notify_fail("你无法学习这项技能。");
   
		notify_fail("你无法学习这项技能。");
		if( !sk->valid_learn(me) ) return 0;

		//增加忘记技能判断 lanwood 2001-05-27
		if(! me->can_learn(arg)) return notify_fail("这项技能你永世不得修习！");

		if( who->query("env/no_teach") )
		{
			who->say("关于这个问题，以后再说吧。");
			who->SendMenu(me);
			return 0;
		}
		if( who->query(snprintf(msg, 255, "env/%s",arg)) )
		{
			who->say("这门武功，今天师傅还不想教你。");
			who->SendMenu(me);
			return 0;
		}
		if( userp(who) )
		{
			int max_leran=400;
			if(sk->query("max_learan"))
				max_leran=sk->query("max_learan");

			if(my_skill>max_leran)
			{
				who->say("徒儿啊，你现在也是一代宗师了，这项技能还是你自己去江湖历练中领悟更高的境界吧。");
				who->SendMenu(me);
				return 0;
			}
			else
			{
				if( who->query("hp") > 350)
				{
					who->receive_damage("hp", 100);
				}
				else
				{
					who->say("徒儿啊，你师傅我今天太累了，改天再说吧。", me);
					who->SendMenu(me);
					return 1;
				}
			}
		}

		if(me->query("hp") < 100) return notify_fail("你今天太累了，结果什么也没有学到。");

		//玩家的技能经验在总经验中的比重不能超过1/3
		if(me->query("sk_exp") * 3 > me->query("combat_exp"))
		{
			who->say("习武重在实践。我看你还是努力提高一下自身素质吧。", me);
			who->SendMenu(me);
			return 1;
		}			

		//现在计算所需的经验
		LONG need_points =  me->skill_need_points(arg);
		LONG need_exp = need_points / me->learn_bonus() + 1;
		
		//计算玩家的经验够不够
		if(me->query_valid_exp() < need_exp)
		{
			who->say(snprintf(msg, 255, "学习%s还需%ld点经验，你再去历练历练吧。", sk->name(1), need_exp), me);
			who->SendMenu(me);
			return 1;
		}
	    
		//计算玩家的技能上限有否达到
		if( strcmp(sk->type(), "martial") == 0 &&
			my_skill >= CChar::level2skill(me->query("level")) ) 
		{
			who->say(snprintf(msg, 255, "你缺乏实战经验，无法领会%s。", sk->name(1)), me );
			who->SendMenu(me);
			return 1;
		}

		me->add("sk_exp", need_exp);
		me->improve_skill(arg, need_points + 1);
		me->receive_damage("hp", 100);

		me->FlushMyInfo();
		//message_vision("$N听了$n的指导，似乎有些心得。", me, who);
		return 1;
		//
	}
	
	DEFINECMD(Abandon)
	{
		CMapping * smap;
		CSkill * sk;
		char msg[255];
	
		if(!me->query_temp("validate"))
			return notify_fail("请先使用 </validate 你的密码 你的暗码> 命令验证你的身份后方可放弃你的技能。");

		if(! strlen(arg)) 
			return notify_fail("你要放弃哪一项技能？");

		smap = me->query_skill_map();
		if(smap->GetCount())
		{
			CVector v;

			smap->keys(v);
			for( int i = 0; i<v.count(); i++)
			{				
				if(strcmp(smap->querystr(v[i]), arg) == 0)
				{
					me->map_skill(v[i]);
				}
			}
		}

		int lvl = me->query_skill(arg, 1);

		if(! me->delete_skill(arg) )
			return notify_fail("你并没有学过这项技能。");

		if(! (sk  = load_skill(arg)) )
			return notify_fail("没有这项技能。");

		me->say(snprintf(msg, 255, "你决定放弃继续学习%s。", sk->name(1)), me);
		me->SendMenu(me);

		//写入日志
		output_error("%s(%s)放弃%ld级%s。From(%s)", me->name(1), me->id(1), lvl, arg, GetIP(me));

		me->FlushMySkill(me);
		return 1;
	}

	DEFINECMD(Enforce)
	{
		int pts;

		if( ! strlen(arg) ) 
			return notify_fail("指令格式：enforce <使出几成内力伤敌>");

		if( ! strlen(me->query_skill_mapped("force")) )
			return notify_fail("你必须先 enable 一种内功。");

		pts = atoi(arg);

		if(! pts )
			me->del("mp_factor");
		else 
		{
			if( pts < 0 || pts > me->query_skill("force") / 2 )
				return notify_fail("你只能用0表示不运内力，或数字表示每一击用几点内力。");
			me->set("mp_factor", pts);
		}

		tell_object(me, "Ok.");
		me->SendState(me);
		return 1;
	}

	DEFINECMD(Kill)	//记仇的
	{
		CChar * who;
		CContainer * env=me->environment();

		if(! (who = GetRoomChar(me, target)) ) return 0;

		if(userp(me) && userp(who) && ! me->querymap("freedom"))
		{
			//if( !me->querymap("corps"))
			//	return notify_fail("必须加入帮会组织才有权PK。");
			if(! who->querymap("corps") && ! who->query("pks") )
			{
				if(who->query_temp("门派大赛/online"))
				{
					if(((CChar *)env)->Query(CChar::IS_USER))
					{
						env=env->environment();
					}
					if(EQUALSTR(env->querystr("base_name"),"fight_room"))
					{
						env=env->environment();
					}
					if(!env->query("门派大赛"))
						return notify_fail("不能对无辜良民痛下杀手。");
					else
						env=me->environment();
				}
				else
					return notify_fail("不能对无辜良民痛下杀手。");
			}
			if(who->query_temp("门派大赛/online"))
			{
				if(((CChar *)env)->Query(CChar::IS_USER))
				{
					env=env->environment();
				}
				if(EQUALSTR(env->querystr("base_name"),"fight_room"))
				{
					env=env->environment();
				}
				if(env->query("门派大赛") && EQUALSTR(me->querystr("family/family_name"),who->querystr("family/family_name")))
					return notify_fail("门派大赛期间，不得对同门暗下杀手。");
				else
					env=me->environment();
			}

			if(who->query_temp("fight/is_fighting"))
			{
				return notify_fail("不能在观战中暗中偷袭。");
			}
			if(who->query_temp("保镖"))
			{
				return notify_fail("你看着众多的趟子手簇拥在他一旁，手一软，不敢再下手。");
			}
		}
	

		if(me->cmd_hit_ob(who, arg))
		{
			if(env->query("biwu"))
			{
				if(userp(me) && userp(who))
				{
					me->set_temp("biwu/ok",1);
					who->set_temp("biwu/ok",1);
					me->set_weight(50000000);
					who->set_weight(50000000);

					CContainer * obj = Do_BiShi(me, who, "以武会友现场", -1);
					obj->set("room_locked", FIGHT_LOCKED);	
					CNpc * umpire = load_npc("pub_umpire");
					umpire->move(obj);
					umpire->set("biwu/a",atoi(me->id(1)));
					umpire->set("biwu/b",atoi(who->id(1)));
				}
			}
			else
			{
				if(me->querymap_temp("biwu"))
				{
					CContainer * env1 = load_room("武陵春风雨楼");
					if(!env1->query("biwu"))
						me->delete_temp("biwu");
				}
				me->set_killer(who);
				who->set_killer(me);
				if(load_room("pk")->query("PK大赛"))
				{
					me->set_temp("last_damage_from",who->object_id());
					who->set_temp("last_damage_from",me->object_id());
				}
				
				if(env->query("city") && userp(who) )
				{
					if(me->querymap("corps"))
					{
						CContainer * env1 = load_room(me->querystr("corps/id"));
						char msg[255];
						if(!env1->query(snprintf(msg,255,"enemy/%s",who->id(1))))
						{
							if(!load_room("pk")->query("PK大赛"))
							{
								CNpc * guard = load_npc("pub_guard");
								guard->move(env);
								guard->set("combat_exp",int(me->query("combat_exp")*1.5));
								guard->set("guard",atoi(who->id(1)));
							}
						}
					}
					else
					{
						if(!load_room("pk")->query("PK大赛"))
						{
							CNpc * guard = load_npc("pub_guard");
							guard->move(env);
							guard->set("combat_exp",int(me->query("combat_exp")*1.5));
							guard->set("guard",atoi(who->id(1)));
						}
					}
				}
				if(userp(me) && userp(who))
					((CUser *)me)->Ready_PK();
			}
			return 1;
		}

		return 0;
	}

	DEFINECMD(Cast)
	{
		const char * skill;
		CSkill * sk;
		CContainer * who = NULL;
		char magic[40];
		
		if(! (who = GetRoomObject(me, target)) )
			who = GetSelfObject(me, target);
		
		if( me->is_busy() )
			return notify_fail("你上一个动作还没有完成，不能施法。");

		if(( (me->environment())->query("no_cast")||(me->environment())->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止使用法术！");

		if(me->query_temp("no_cast"))
			return notify_fail("你不能立刻使用法术!");

		analyse_string(arg, magic, 40);
		
		//判断角色是否掌握该技能。
		skill = arg;
		if(me->query_skill(skill, 1) < 1) 
			return notify_fail("你还不会这种技能！");

		sk = load_skill(skill);

		//也有例外，如果技能是"special"类型可以不装备直接使用。		
		if(! sk->query("special"))
		{
			skill = me->query_skill_mapped(arg);
			
			if(! strlen(skill))
			{
				return notify_fail("请先准备技能。");
			}
		
			sk = load_skill(skill);

			char valid_types[7][10] = {"unarmed", "finger", "hand", "cuff", "claw", "strike","leg"};
			CContainer * weapon = me->query_weapon();

			if(DIFFERSTR(arg, "force"))	//非内功，则要判断武器
			{
				int bCanUse = 0;
				for(int i=0; i<7; i++)
				{
					if(strcmp(arg, valid_types[i]) == 0)
					{
						//检查武器
						if(! weapon || DIFFERSTR(weapon->querystr("skill_type"), valid_types[i]) )
							bCanUse = 1;
					}
				}

				if(bCanUse && weapon)
					return notify_fail("你必须空手！");

				//if(EQUALSTR(arg, "parry") && weapon)
				//	return notify_fail("使用招架无法发挥这项法术!");

				if(!bCanUse && (DIFFERSTR(arg, "parry") && DIFFERSTR(arg, "dodge") )
					&& (! weapon || DIFFERSTR(weapon->querystr("skill_type"), arg ) ))
					return notify_fail("使用的武器不对！");
			}
		}
		
		notify_fail("你所使用的技能不支持该法术。");
		if(sk->Cast(magic, me, who) )
		{
			//检查who 是否存在
			if(g_LastDestructObject == target)
				who = 0;

			me->improve_skill(skill, 1 + me->query("level") / 5, 1);

			if(strcmp(magic, "lifeheal") == 0) return 1;
			if(strcmp(magic, "recover") == 0) return 1;
			if(strcmp(magic, "powerup") == 0) return 1;
			if(strcmp(magic, "heal") == 0) return 1;
			if(strcmp(skill, "begging") == 0) return 1;
			if(strcmp(skill, "persuading") == 0) return 1;

			
			//判断对象是否为NPC
			if(! who || ! userp(who) || me == who )
			{
				if(DIFFERSTR(skill,"roar")) return 1;
			}

			if(userp(me))
			{
				if(me->querymap_temp("biwu"))
				{
					CContainer * env1 = load_room("武陵春风雨楼");
					if(!env1->query("biwu"))
						me->delete_temp("biwu");
				}
				((CUser *)me)->Ready_PK();
			}

			return 1;
		}

		return 0;
	}

	//加入战斗 join 12 1
	DEFINECMD(JoinBattle)
	{
		//禁止在设置为no_join的场景使用JoinBattle命令 秦波 2002-10-09
		if(((me->environment())->query("no_join")||(me->environment())->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止加入战斗");

		int team;
		CChar * sprite;
		CFightRoom * obj;
		CContainer * who;
		char msg[512];

		me = FindMaster(me);

		if(me->is_busy())
			return notify_fail("你现在正忙。");

		//要求是战斗对象
		if(! (who = GetRoomObject(me, target)) ) return 0;
		if(! who->Query(CChar::IS_FIGHTROOM)) return 0;
		if(! atoi(arg))		//加入A队
			team = CFightRoom::FIGHT_TEAM_A;
		else
			team = CFightRoom::FIGHT_TEAM_B;

		obj = (CFightRoom *)who;
		if(! obj->Can_Join(team, me))
		{		
			DTItemList * list = obj->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj_smash = list->GetNext(p);
				if(! obj_smash->is_character()) continue; 
				CChar * target = (CChar *)obj_smash;  
				if(!userp(target))	continue;
				if((target->query_temp("fight/is_fighting") && target->query_temp("net_dead")))
				{
					obj->set("smash",1);
					break;
				}
			}
			if(obj->querystr("lock_msg")[0] && !obj->query("smash"))
				return notify_fail("%s", obj->querystr("lock_msg"));

			if(EQUALSTR((me->environment())->querystr("area"),"武陵") && !obj->query("smash")) 
				return notify_fail("练你自己的，看别人的做什么!");

			if(!obj->query("smash"))
				return notify_fail("此战斗不能加入!");
		
		}
//禁止加入NPC一方进行战斗  秦波		
		int team_obj=100;
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		CContainer * env = load_room("pk");
		while(p) 
		{ 
			CContainer * obj1 = list->GetNext(p);
			if(! obj1->is_character()) continue; 
			CChar * target = (CChar *)obj1;  
			if(!userp(target)  && !target->query("help") && DIFFERSTR(target->name(1),"天山铁姥") && DIFFERSTR(target->name(1),"金牌捕快") &&
				!(EQUALSTR(target->id(1),"biao che") && atoi(target->querystr("劫镖者"))) &&
				!(env->query("mj/start") && EQUALSTR(target->querystr("family/family_name"), "明教")&& !userp(target)))
			{
				team_obj=target->query_temp("fight/fight_team");
				break;
			}
		}
		if(team_obj!=100 && team==team_obj && userp(me) && !obj->query("smash") )
		{
			return notify_fail("此战斗禁止加入NPC一方!");
		}
		else
		{
			sprite = FindSprite(me);
			
			me->move(obj);
			if(sprite)
			{
				sprite->move(obj);
				obj->Join_Team(sprite, team);
			}
			
			obj->Join_Team(me, team);
			
			tell_room(obj, snprintf(msg, 255, "%s加入%s.", me->name(), obj->name()));
			tell_room(me->environment(), snprintf(msg, 255, "%s加入战队%d.", me->name(), team));
			
			//PK Mark!
			if(userp(me))
				((CUser *)me)->Ready_PK();
		}
		return 1;
	}
	
	//观战
	DEFINECMD(Guard)
	{
		CContainer * obj;
		char msg[255];

		if(me->is_busy())
			return notify_fail("你现在正忙。");

		//要求是战斗对象
		if(! (obj = GetRoomObject(me, target)) ) return 0;
		if(! obj->Query(CChar::IS_FIGHTROOM)) return 0;
		if(DIFFERSTR(obj->name(1),"以武会友现场") && DIFFERSTR(obj->name(1),"比武招亲"))
		{
			CMapping * m = obj->query_entire_dbase();
			if(! m->undefinedp("no_guard") && ! wizardp(me) )
			{
				const char * ptr = m->querystr("no_guard");
				return notify_fail(ptr[0] ? ptr : "此战斗不允许观战!");
			}
			
			int flee = m->query("room_locked");
			if(flee & FIGHT_NO_JOIN) return notify_fail("此战斗被锁住，无法观战。");
		}
	
		me->move(obj);					
		message_vision("$N加入观战。", me);
		tell_room(obj->environment(), snprintf(msg, 255, "%s观看%s。", me->name(), obj->name()));
		return 1;
	}

	DEFINECMD(Tell)
	{
		//禁止在设置为no_tell的场景使用Tell命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_tell")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止私聊。");


		char msg[512];
		CChar * who;
		
		if(!(who = find_player(target)) ) return notify_fail("没有这个人。。。");

		if(! living(who) || who->query_temp("net_dead"))
			return notify_fail("对方听不到你讲话。");
	
		char key[80];
		
		snprintf(key, 80, "notell/%s", me->querystr("id"));

		if (! wizardp(me) && (who->query_temp(key) 
			|| who->query_temp("notell/all")) )
			return notify_fail("%s不接受你的悄悄话。", who->name(1)); 	

		if(! g_Channel.check_channel_msg(me, "tell", arg, 0))
			return 0;

		snprintf(msg, 512, "&C=%d&i=%s&n=%s&M=%s&", 
			TELLOBJECT,
			me->querystr("id"),
			me->name(1), arg);
		who->SendCommand(msg, 1);

		tell_object(me, snprintf(msg, 400, "$HIG【私聊】你告诉%s：%s", who->name(), arg));

		//判断对方是否发呆中
		int idle;
		if(userp(who) && (idle = ((CUser *)who)->query_idle()) > 180)
		{
			tell_object(me, snprintf(msg, 400, "$HIG%s已经发呆了%ld秒，可能不能马上回答你哦～", who->name(), idle));
		}

		return 1;
	}

	//piao
	DEFINECMD(wench)
	{
		char msg[255];
		CChar * who;
		CContainer * where = me->environment();

		if(! where->query("wench_room"))	
			return 0;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要对谁下这个指令？");

		if(who->query_condition("prostitute") < 1)			
			return notify_fail("对方可不愿意理你哦！");

		if(DIFFERSTR(me->querystr("gender"), "男性"))
			return notify_fail("你是心有余而力不足哦！");

		if(me->query("hp") < 1000 )
			return notify_fail("你是心有余而力不足哦！");
		
		LONG value = who->query("value") / 3;	//身价
		if(! CMoney::Player_Pay(me, value))
			return notify_fail("%s身价%ld。你囊中羞涩，恐怕支付不起！", who->name(), value);
		
		message_vision(snprintf(msg, 255, "\n\n$HIY$N朝$n哈哈一笑，轻挑道：姑娘来来，陪%s玩玩！", query_self_rude(me)), me, who);
		me->call_out(do_wench, 5, who->object_id());

		me->start_busy(4);
		who->start_busy(4);
		return 1;
	}

	static void do_wench(CContainer * ob, LONG param1, LONG param2)
	{
		char msg[255];
	
		CChar * me = (CChar *)ob;
		CChar * who = (CChar *)(me->environment())->Present(param1);

		if(! who) return;

		//判断成功率
		int caiqi = who->query_skill("literate", 1) + who->query_skill("music", 1);
		int succ = me->query_skill("literate", 1) + who->query_skill("music", 1);
		if(random(succ + caiqi) < caiqi)	//卖艺不卖身
		{
			message_vision("$HIY\n\n$n款款坐下，为$N弹了一支曲子。\n曲毕，$n对$N微微一礼道：对不起，小女子卖艺不卖身。", me, who);			
		}
		else
		{
			if(who->query_temp("selled"))
				message_vision("$HIY\n\n$n惧怕的看着$N，垂泪道：小女子命若黄连，大爷求你放过我一次吧。", me, who);
			else
				message_vision("$HIY\n\n$n娇笑着跌进$N怀中，嗲声道：你好坏~~~~~", me, who);
		
			me->command("unwield 0 all");
			who->command("unwield 0 all");

			message_vision("\n$HIR$N哈哈大笑着，抱起$n，吹熄灯烛……", me, who);
			tell_object(me, snprintf(msg, 255, "$HIY\n\n你搂着%s温软的身体，不由得心醉神迷．．．\n\n\n", who->name()));
			tell_object(who, snprintf(msg, 255, "$HIY\n\n你躺在%s的怀里，不由得心醉神迷．．．\n\n\n", me->name()));
			
			me->set("last_sleep", current_time);
			who->set("last_sleep", current_time);
			me->set_temp("block_msg/all",1);
			who->set_temp("block_msg/all",1);
			message_vision("$HIY $N和$n钻入被中，搂在一起睡着了．．．\n\n\n",me, who);
			
			me->disable_player("睡梦中");
			who->disable_player("睡梦中");

			me->call_out(wakeup2, random(45 - me->query_con()) + 10, who->object_id());
			who->call_out(wakeup2, random(45 - who->query_con()) + 10, me->object_id());        

			me->add("wench/sleep", 1);
			who->add("wench/sleep", 1);
		}

		who->add("hp", -450);
		
		//增加业绩
		me->add("wench/take", 1);	//接待数量
	}

	//文本指令
	DEFINECMD(Sleep)
	{
		CContainer * where = me->environment();
   
		if( ! where->query("sleep_room") &&
			! me->query_temp("force_sleep") &&
			DIFFERSTR(me->querystr("family/family_name"), "丐帮") )
			return notify_fail("这里不是睡觉的地方。");

		if (me->is_busy())
			return notify_fail("你正忙着呢！");

		if( me->is_fighting() )
			return notify_fail("战斗中不能睡觉！");

		//if (where->query("hotel") && !(me->query_temp("rent_paid")))
		//{
		//	message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!",me);
		//	return 1;
		//}
        
		if ( (current_time - me->query("last_sleep") ) < 90 )
			return notify_fail("你刚睡过一觉, 先活动活动吧。 ");
			
		if( ! target || target == me->object_id())
        {
			me->disable_player("睡梦中");
			int rnd;

			if (where->query("sleep_room"))
			{
				tell_object(me, "你往被中一钻，开始睡觉。\n不一会儿，你就进入了梦乡。");
				me->set("last_sleep", current_time);
				me->set_temp("block_msg/all", 1);
				message_vision("$N往被中一钻，不一会便鼾声大作，进入了梦乡。",me);
				rnd = random((60 - me->query_con()) / 3);
			}
			else
			{ 
				tell_object(me, "你就地一躺，开始睡觉。\n不一会儿，你就进入了梦乡。");
				me->set("last_sleep", current_time);
				me->set_temp("block_msg/all",1);
				message_vision("$N就地一躺，不一会便鼾声大作，进入了梦乡。",me);
				rnd = 10 + random((100 - me->query_con()) / 3);
			}

			//if (where->query("hotel"))
			//	me->delete_temp("rent_paid");
				
			if ( rnd < 1 ) rnd = 0;
			me->call_out(wakeup1, rnd + 10);

			return 1;
		}

		char msg[255];
		CChar * obj;

		if(! (obj = GetRoomChar(me, target)) )
			return notify_fail("你想跟谁一起睡？");
		
		if( ! userp(obj))
			return notify_fail("人家可不愿理你！");

 
		//can't sleep with npc...
		
		if(! (EQUALSTR(me->querystr("gender"), "男性") && EQUALSTR(obj->querystr("gender"), "女性")
			  || EQUALSTR(me->querystr("gender"), "女性") && EQUALSTR(obj->querystr("gender"), "男性"))  )
			  return notify_fail("你们没法睡哦！");

		if( ! obj->Query(CChar::IS_LIVING) )
			return notify_fail("%s没法跟你睡了。", obj->name()); 

		if (!where->query("sleep_room"))   
			return notify_fail("就在这里？不太好吧。");

		if (obj->is_busy())
			return notify_fail("对方正忙着呢！");

		if( me->query("hp") * 100 / me->query("max_hp") < 50 )
			return notify_fail("你现在是心有余而力不足。");

		if(me->querymap("condition") && !me->query_condition("wc_poison"))
			return notify_fail("你的呼吸慢慢变的急促起来，但现在中毒在身，看起来是心有余而力不足。");

		if( obj->querymap("condition") && !obj->query_condition("wc_poison"))
			return notify_fail("对方的呼吸慢慢变的急促起来，但对方看起来象是中毒在身，实在是心有余而力不足。");

		if( obj->query_temp("apply/index") )
			return notify_fail("对方穿的这么整齐，好象是要打算出门去的吧，现在还有空睡觉吗？");

		if( me->query_temp("apply/index") )
			return notify_fail("你穿的这么整齐，是去上街还是要睡觉呢？");

		if( userp(obj) && obj->query_temp("pending/sleep") != me->object_id()) 
		{
			message_vision("\n$RED$N含情脉脉地对$n说：我．．．\n\n", me, obj);
						
			me->set_temp("pending/sleep", obj->object_id());
			tell_object(obj, snprintf(msg, 255, "$YEL看来%s(%s)很想跟你．．．如果你愿意，请与其交谈。", me->name(), me->id()));
			tell_object(me, "$YEL对方正在考虑中．．．\n");

			//增加菜单交互 lanwood 2001-03-24
			/*	char show[80], tmp[40];

				me->AddMenuItem(snprintf(show, 80, "同意和%s睡觉", me->name()),
					snprintf(tmp, 40, "$0sleep %ld", me->object_id()), obj);
				me->AddMenuItem("离开", "", obj);
				me->SendMenu(obj);
			*/
			return 1;
		}

		message_vision("$RED\n$N冲着$n会心地一笑，点了点头。\n\n", me, obj);
		
		me->command("unwield 0 all");
		obj->command("unwield 0 all");
		//清除所有装备的附加效果  秦波 2002-10-09
		//me->delete_temp("apply");
		//obj->delete_temp("apply");
		me->UpdateMe();
		obj->UpdateMe();
		
		if(EQUALSTR(me->querystr("gender"), "男性"))
		{
			tell_object(me, snprintf(msg, 255, "$HIY\n\n你搂着%s温软的身体，不由得心醉神迷．．．\n\n\n", obj->name()));
			tell_object(obj, snprintf(msg, 255, "$HIY\n\n你躺在%s的怀里，不由得心醉神迷．．．\n\n\n", me->name()));
		}
		else
		{
			tell_object(obj, snprintf(msg, 255, "$HIY \n\n你搂着%s温软的身体，不由得心醉神迷．．．\n\n\n", me->name()));
			tell_object(me, snprintf(msg, 255, "$HIY\n\n你躺在%s的怀里，不由得心醉神迷．．．\n\n\n", obj->name()));
		}
		
		me->set("last_sleep",current_time);
		obj->set("last_sleep",current_time);
		me->set_temp("block_msg/all",1);
		obj->set_temp("block_msg/all",1);
		message_vision("$HIY $N和$n钻入被中，搂在一起睡着了．．．\n\n\n",me,obj);
		
		me->disable_player("睡梦中");
		obj->disable_player("睡梦中");

		me->call_out(wakeup2, random(45 - me->query_con()) + 10, obj->object_id());
		obj->call_out(wakeup2, random(45 - obj->query_con()) + 10, me->object_id());
        
		return 1;
	}

	static void wakeup2(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		
		int kee_cost = 50 + 5* (me->query("str") - me->query("con"));
				
		if(kee_cost > me->query("max_hp")/2) 	
			kee_cost = me->query("max_hp") / 2 + 1;	
    		
		if (me->query("mp") < me->query("max_mp"))
			me->set("mp", me->query("max_mp"));
			
		me->add("max_atman",1);
		me->add("hp", -kee_cost);	

		me->enable_player();
 
		while( me->environment()->is_character() )
			me->move((me->environment())->environment());

		//sleep后,春毒自解
		me->apply_condition("wc_poison", 0);
		
		if(EQUALSTR(me->querystr("gender"), "男性"))
		{
			message_vision("$HIY$N醒了过来，似乎还沉浸在幸福之中。",me);
			me->set_temp("block_msg/all", 0l);
			tell_object(me, "你醒了过来，似乎还沉浸在幸福之中。");
			return;
		}
			
		
		// we add bearing function here. wuliao@xyj Feb. 1997	
		message_vision("$HIY$N醒了过来，脸上还挂着甜蜜的笑容。", me);
		me->set_temp("block_msg/all", 0l);
		tell_object(me, "你醒了过来，脸上还挂着甜蜜的笑容。");
		
		//		if (me->query("husband"))
		//			obj = present ( keys(me->query("husband"))[0], where);
	// added by pickle 10-13-97
	// sleep with someone other than husband will also give child.
		CChar * who = (CChar *)(me->environment())->Present(param1);

		if(! who) return;
		
		if(me->query("max_atman") < me->query("wench/sleep") * 5)
			return;

		if(me->query("max_atman") < 40 || 
			me->query("max_atman") / 100 < me->query("child")) 
				return;
					
		if(who->query("max_atman")<40 || 
			who->query("max_atman")/100 < who->query("child"))
		{
			message_vision("$HIY\n$N忽觉腹中一阵颤动，不过马上又平静下来。\n",me);
			return;
		}
		
		//必须生在男方家里。
		CContainer * where = me->environment();
		
		if( DIFFERSTR(where->querystr("owner"), who->querystr("id")))
		{
			message_vision("$HIY\n$N忽觉腹中一阵颤动，不过马上又平静下来。\n",me);
			return;
		}

		me->set_temp("is_bearing",1);
		me->start_busy(100);
		who->start_busy(100);
				
		message_vision("$HIY\n$N忽觉腹中一阵颤动，赶紧拉住$n的手，柔声说道：要生了! \n", me, who);
		me->call_out(birth1, 15, param1);			
	}

	static void birth1(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = (CChar *)(me->environment())->Present(param1);

		if(! who) return;

		message_vision("$HIY\n$N已是大汗淋漓，一直都在呼天抢地，双手紧紧扣住$n的手不放。\n\n婴儿已经探出了头．．．\n", me, who);
		me->call_out(birth2, 15, param1);		
	}

	static void birth2(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = (CChar *)(me->environment())->Present(param1);

		if(! who) return;

		message_vision("$HIY \n「哇」．．．，婴儿出世了！\n\n$N面色苍白，斜倚在床头，看看孩子满意地露出一丝微笑。\n", me);
		me->start_busy(1);
		who->start_busy(1);
		me->set("hp",0l);
		
		CNpc * baby = load_npc("monster_baby");

		char msg[255];

		baby->set("long", snprintf(msg, 255, "%s这是%s和%s的孩子。", baby->Long(), me->name(1), who->name(1)));
		
		if (random(100) < 50)
		{
			baby->set("gender","男性");
			baby->set_name( snprintf(msg, 255, "小%s", who->name(1)));
			baby->set("icon", CChar::boy1);
		}	
		else
		{	
			baby->set("gender","女性");
			baby->set_name( snprintf(msg, 255, "小%s", me->name(1)));
			baby->set("icon", CChar::girl1);
		}
		
		me->add("child",1);
		who->add("child",1);
		baby->set("mother", me->querystr("id"));
		baby->set("father", who->querystr("id"));
		
		int number=me->query("child");
		
		me->set(snprintf(msg, 255, "child_%ld/gender", number), baby->querystr("gender"));
		me->set(snprintf(msg, 255, "child_%ld/long", number),baby->querystr("long"));
		me->set(snprintf(msg, 255, "child_%ld/name", number), baby->querystr("name"));
		me->set(snprintf(msg, 255, "child_%ld/father", number), who->querystr("id"));
		
		//记录到房间
		CContainer * where = me->environment();
		where->set_temp(snprintf(msg, 255, "baby_%ld", number), baby->object_id());
		
		number=who->query("child");
		who->set(snprintf(msg, 255, "child_%ld/gender", number), baby->querystr("gender"));
		who->set(snprintf(msg, 255, "child_%ld/long", number),baby->querystr("long"));
		who->set(snprintf(msg, 255, "child_%ld/name", number),baby->querystr("name"));
		who->set(snprintf(msg, 255, "child_%ld/mother", number),me->querystr("id"));
		
		me->delete_temp("is_bearing");
		me->Save();
		who->Save();
		//this needs to be put at the last since
		//can only move the baby after it's parameters are set.
			
		if(! baby->move(me->environment()) )
		  baby->move((me->environment())->environment());
	}	

	DEFINECMD(Exercise)
	{
		//禁止在设置为no_exercise的场景使用Exercise命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_exercise")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止练功。");

		int hp_cost, busy_time;
   
		if( (me->environment())->query("no_fight") )
		    return notify_fail("安全区内禁止练功。");
         
        if (me->is_busy() || me->query_temp("pending/exercising"))
            return notify_fail("你现在正忙着呢。");

		if( me->is_fighting())
			return notify_fail("战斗中不能练内功，会走火入魔。");

		if( ! strlen(me->query_skill_mapped("force")) )
			return notify_fail("你必须先用 enable 选择你要用的内功心法。");

		hp_cost = me->query("env/exercise");
		if( ! hp_cost) 
			return notify_fail("你要花多少气练功？用set exercise 10设置。");
		if( hp_cost < 10 ) return notify_fail("你最少要花 10 点「气」才能练功。用set exercise 10设置。");

		if( me->query("hp") < hp_cost )
			return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。");

		tell_object(me, "你坐下来运气用功，一股内息开始在体内流动。", "exercise");

		busy_time = hp_cost/20;
		me->start_busy(busy_time + 1);
		me->set_temp("pending/exercising", 1);
   		me->set_temp("exercise_cost", hp_cost);
		
		message_channel("exercise", "$N盘膝坐下，开始修炼内力。", me);
		me->start_busy(exercising, halt_exercise);
		me->SendState();
		return 1;
	}

	static int exercising(CChar * me)
	{		
		int exercise_cost = me->query_temp("exercise_cost");
		int neili_gain = 1 + me->query_skill("force") / 5;
		CContainer * where = me->environment();

		if (exercise_cost < neili_gain) neili_gain = exercise_cost;
		if (exercise_cost < 1)
		{
			if (me->query("mp") > me->query("max_mp") * 2)
				me->set("mp", me->query("max_mp") * 2);

			return 0;
		}

		if(me->query("hp") < neili_gain)
		{
			message_channel("exercise", "$N一口真气没上来，终止了打坐。", me);

			//防止内力过高
			if (me->query("mp") > me->query("max_mp") * 2)
				me->set("mp", me->query("max_mp") * 2);

			me->SendState();
			me->FlushMyInfo();

			return 0;
		}
			
		me->add("mp", neili_gain);
		me->set_temp("exercise_cost", exercise_cost -= neili_gain);

		if(where->query("xuanbing"))
			me->add("hp", neili_gain/3);
		if(where->query("hanyuchuang"))
			me->add("hp", neili_gain/2); 

		me->add("hp", -neili_gain);

		if (exercise_cost > 0)
			return 1;

		me->set_temp("pending/exercising", 0l);
		message_channel("exercise", "$N运功完毕，深深吸了口气，站了起来。", me);
		if (me->query("mp") >= me->query("max_mp") * 2)
		{
			if (me->query("max_mp") > me->query_skill("force") * 10) 
			{
				tell_object(me, "你的内力修为似乎已经达到了瓶颈。", "exercise");
				me->set("mp", me->query("max_mp"));
			}
			else 
			{
				me->add("max_mp", 1);
				me->set("mp", me->query("max_mp"));
				tell_object(me, "你的内力增加了！！", "exercise");
			}
		}

		me->SendState();
		me->FlushMyInfo();
		return 0;
	}

	static int halt_exercise(CChar * me, CChar * who, char * how)
	{
		if (me->query("mp") > me->query("max_mp") * 2)
			me->set("mp", me->query("max_mp") * 2);
		me->set_temp("pending/exercising", 0l);

		//显示中止原因信息
		if(strcmp(how, "halt") == 0)
			message_vision("$N把正在运行的真气强行压回丹田，站了起来。", me);
		else if(strcmp(how, "kill") == 0)
			message_vision("受到$n攻击，$N强行压下一口真气，站了起来！", me, who);
		else
			message_vision("$N一口真气没上来，终止了打坐。", me);

		me->FlushMyInfo();
		me->SendState();
		return 1;
	}

	DEFINECMD(Enable)
	{
		CMapping * m;
		char msg[255];
		char valid_types[22][10] = {"music", "dagger", "hammer", "leg", "axe", "unarmed", "sword", "blade", 
					"staff","club",	"throwing",	"force",
					"parry", "dodge", "magic", "whip",
					"lingfa", "finger", "hand",	"cuff",
					"claw", "strike"};
		
		if(strcmp(arg, "check") == 0 && wizardp(me))
		{
			me = find_player(target);
			if (!me) return notify_fail("没有这个人。");
		}

		if(! strlen(arg) || strcmp(arg, "check") == 0) 
		{
			m = me->query_skill_map();
			if(!m->GetCount())
				return notify_fail("你现在没有使用任何特殊技能。");

			tell_object(me, "以下是你目前使用中的特殊技能。");
			for(int i = 0; i < 22; i++)
			{
				if( ! me->query_skill(valid_types[i]) ) continue;

				const char * ptr = m->querystr(valid_types[i]);
				tell_object(me, snprintf(msg, 255, "%s：%s  有效等级：%d", 
					valid_types[i],
					ptr[0] ? ptr : "无",
					me->query_skill(valid_types[i])) );
			}
			return 1;
		}

		char ski[80], map_to[40];
		char base_skill[10];
		strncpy(ski, arg, 80);
		analyse_string(ski, map_to, 40);
		
		if(! strlen(map_to))
			return notify_fail("指令格式：enable [<技能种类> <技能名称>|none]");

		base_skill[0] = 0;

		for(int i=0; i<22; i++)
			if( strcmp(valid_types[i], ski) == 0 )
				strncpy(base_skill, valid_types[i], 10);

		if(! base_skill[0])
			return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。");

		if( strcmp(map_to, "none") == 0 )
		{
			me->map_skill(base_skill);
			me->delete_temp("perf_quick");
			//me->reset_action();
			me->FlushMySkill(me);
			tell_object(me, "Ok.");
			return 1;
		}
		else if( strcmp(map_to, base_skill) == 0 )
		{
			tell_object(me, snprintf(msg, 255, "「%s」是基础，不需要 enable。", base_skill));
			return 1;
		}

		if( !me->query_skill(map_to, 1) )
			return notify_fail("你不会这种技能。");

		//   if( !me->query_skill(ski, 1) )
			//     return notify_fail("你连「" + to_chinese(ski) + "」都没学会，更别提"
			//        + to_chinese(map_to) + "了。\n");

		if( ! load_skill(map_to)->valid_enable(base_skill) )
			return notify_fail("这个技能不能当成这种用途。");

		me->map_skill(base_skill, map_to);
		me->delete_temp("perf_quick");
		//me->reset_action();
		tell_object(me, "Ok.");
   
	    if( strcmp(base_skill, "force" ) == 0)
		{
			tell_object(me, "你改用另一种内功，内力必须重新修炼。");
			me->set("mp", 0l);
			me->set("mp_factor", 0l);
			me->receive_damage("hp", 0l);
			me->FlushMyInfo();
		} 

		//判断是否用于组合 lanwood 2001-02-26
		if( strlen(me->query_skill_prepared(base_skill)) )
		{
			CMapping * prepare = me->query_skill_prepare();
			prepare->clear();
			tell_object(me, "你改用另一种空手技能，空手技能必须重新激发。");
		}

		me->FlushMySkill(me);
		return 1;
	}

	//拳术组合 有双手互博可以任意组合空手技能。
	DEFINECMD(Prepare)
	{
		CMapping * smap = me->query_skill_map();
		char basic1[10], basic2[10];
		char valid_types[7][10] = {"unarmed", "finger", "hand", "cuff", "claw", "strike", "leg"};
		
		if( ! smap->GetCount() )
			return notify_fail("你现在没有使用任何有效特殊技能。");

		CMapping * pmap = me->query_skill_prepare();
		
		if( strcmp(arg, "none") == 0 ) 
		{
			if(! pmap->GetCount() )
				return notify_fail("你现在没有组合任何特殊拳术技能。");

			pmap->clear();

			tell_object(me, "取消全部技能准备。");
			me->FlushMySkill(me);
			return 1;
		}

		if ( pmap->GetCount() >= 2 ) 
			return notify_fail("你现在已经组合了两种特殊技能。");

		char map_to[40];
		analyse_string(arg, map_to, 40);
		
		basic1[0] = 0; basic2[0] = 0;

		if(map_to[0])
		{
			if ( pmap->GetCount() == 1 ) 
					return notify_fail("你已准备有一种技能了。");

			if( !me->query_skill(arg, 1) || !me->query_skill(map_to, 1) )
					return notify_fail("你至少不会这两种技能其中之一。");

			if( ! load_skill(arg)->valid_combine(map_to) 
				&& random(me->query_skill("hubo", 1)) < 50 )
					return notify_fail("这两种拳术技能不能组合。");

			for(int i = 0; i < 7; i++)
			{
				if( smap->querystr(valid_types[i]) == arg ) strncpy(basic1, valid_types[i], 10);
				if( smap->querystr(valid_types[i]) == map_to ) strncpy(basic2, valid_types[i], 10);
			}

			if ( !basic1[0] || !basic2[0] ) 
					return notify_fail("这两种拳术尚未激发或目前不能准备。");

			me->prepare_skill(basic1, arg);
			me->prepare_skill(basic2, map_to);

			me->FlushMySkill(me);
			tell_object(me, "完成技能准备。");
			return 1;
		}
			
		if(pmap->GetCount() <= 1 ) 
		{
			if( !me->query_skill(arg, 1) )
				return notify_fail("你不会这种技能。");

			CVector v;

			pmap->values(v);
			if( pmap->GetCount() == 1 
				&& ! load_skill(arg)->valid_combine(v[0])
				&& random(me->query_skill("hubo", 1)) < 50 )
				return notify_fail("这种技能不能於你现有技能组合。");

			for (int i=0; i< 7; i++) 
			{
				if( EQUALSTR(smap->querystr(valid_types[i]), arg) ) strncpy(basic1, valid_types[i], 10);
			}

			if ( !basic1[0] ) 
				return notify_fail("这种技能尚未激发或目前不能准备。");

			me->prepare_skill(basic1, arg);

			me->FlushMySkill(me);
			tell_object(me, "完成技能准备。");
	
			return 1;
		}
		return 1;
	}

	DEFINECMD(Study)
	{
		//禁止在设置为no_study的场景使用Study命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_study")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止练功。");
		
		CContainer * where;
		CContainer * ob;
		CMapping * skill;
		CSkill * sk;
		int my_skill;
		char msg[255];
		const char * skill_name;

		where = me->environment();
		if(where->query("no_fight") || where->query("no_magic") )
			return notify_fail("安全区内禁止练功。");
                        
		if( me->is_fighting() )
			return notify_fail("你无法在战斗中专心下来研读新知！");

        if (me->is_busy() || me->query_temp("pending/exercising"))
            return notify_fail("你现在正忙着呢。");

		if(! (ob = GetSelfObject(me, target)) )
			return notify_fail("你要读什么？");


		if( ! (skill = ob->querymap("skill")) )
			return notify_fail("你无法从这样东西学到任何东西。");

		if( ! me->query_skill("literate", 1) )
			return notify_fail("你是个文盲，先学学读书识字(literate)吧。");

		tell_room(me->environment(), snprintf(msg, 255, "%s正专心地研读%s。", me->name(), ob->name()), me, "study");
		skill_name = skill->querystr("name");
        my_skill = me->query_skill(skill_name, 1);

		sk = load_skill(skill_name);
		
		if( me->query_combat_exp() < skill->query("exp_required") ) 
		{
			return notify_fail("你的等级不够，再怎么读也没用。");			
		}

        if ( skill->query("difficulty") - me->query_int() > 0 
			|| my_skill < skill->query("min_skill") )
             return notify_fail("以你目前的能力，还没有办法学这个技能。");
	
		if( ! sk->valid_learn(me) ) return 0;

		//增加忘记技能判断 lanwood 2001-05-27
		if(! me->can_learn(skill_name)) return notify_fail("这项技能你永世不得修习！");

		int cost = skill->query("jing_cost");
		
		cost = cost + cost * (skill->query("difficulty") - me->query_int()) / 20;

		if (cost < 5 ) cost =5;	//minimum cost

		if( my_skill > skill->query("max_skill") ) 
		{
			return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。");			
		}

		int succ = 0;

		if( me->query("hp") > cost ) 
		{
			if( strcmp(sk->type(), "martial") == 0
				&&	my_skill > CChar::level2skill(me->query("level")) ) 
			{
				notify_fail("你的等级太低，对%s上面所说的东西总是无法领会。", ob->name());
			} 
			else 
			{
				tell_object(me, snprintf(msg, 255, "你研读有关%s的技巧，似乎有点心得。", sk->name(1)), "study");
                me->improve_skill(skill_name, random(me->query_skill("literate", 1) / 2 + 1) + 1);
				succ = 1;
			}
		} 
		else 
		{
			cost = me->query("hp");
			notify_fail("你现在过于疲倦，无法专心下来研读新知。");
		}

		me->receive_damage("hp", cost );
		return succ;
	}

	DEFINECMD(Practice)
	{
		//禁止在设置为no_practice的场景使用Practice命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_practice")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止练功。");

		char msg[255];

		if(( (me->environment())->query("no_fight") &&!(me->environment())->query("no_吼")) || 
			(me->environment())->query("no_magic") )
			return notify_fail("安全区内禁止练功。");

		if (me->is_busy())
                return notify_fail("你现在正忙着呢。");

		if( me->is_fighting() )
			return notify_fail("你已经在战斗中了，学一点实战经验吧。");

		if(! strlen(arg))
			return Enable(me, 0, arg);

		const char * skillname = me->query_skill_mapped(arg);
		if( ! skillname[0] )
			return notify_fail("你只能练习用 enable 指定的特殊技能。");

		int skill_basic = me->query_skill(arg, 1);
		int skill = me->query_skill(skillname, 1);

		if( skill < 1 )
			return notify_fail("你好像还没「学会」这项技能吧？最好先去请教别人。");
		
		if( skill_basic < 1 )
			return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。");

		if( skill  >= CChar::level2skill(me->query("level")) )
			return notify_fail("你的等级不够，练得再多也没用。");

		notify_fail("你现在不能练习这项技能。");

		CSkill * sk = load_skill(skillname);
		if( ! sk->valid_learn(me) ) return 0;

		//增加忘记技能判断 lanwood 2001-05-27
		if(! me->can_learn(skillname)) return notify_fail("这项技能你永世不得修习！");

		notify_fail("你试着练习%s但是并没有任何进步。", sk->name(1));

        if(skill_basic <= skill && random(100)==0)
			tell_object(me, snprintf(msg, 255, "你的%s很难提高了，还是向你师父请教请教吧！", sk->name(1)));

		if( sk->practice_skill(me) ) 
		{
			me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
			tell_object(me, snprintf(msg, 255, "$CYN你的%s进步了！",   sk->name(1)), "practice");
			me->FlushMyInfo();
			return 1;
		}
		else 
			return 0;
		
	}

	DEFINECMD(Fight)
	{
		char msg[255];
		CChar * who;
		CContainer * env = me->environment();

		//----------------------------------------
		//增加坐标信息	1.7版本 lanwood 2001-03-23
			char szY[40];
			analyse_string(arg, szY, 40);
			LONG x = atol(arg);
			LONG y = atol(szY);

			if(x && y)
			{
				me->set_temp("map/ex", x);
				me->set_temp("map/ey", y);
			}
		//----------------------------------------

		if(me->query_temp("biwu")) 
			return notify_fail("此命令比武期间禁止使用！");
				
		if(( env->query("no_fight") || env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止战斗。");

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要和谁切磋？");
		
		if(env->Query(CChar::IS_FIGHTROOM)) return 1;		//已经在战斗了。

		if( !living(who) )
			return notify_fail("%s已经无法战斗了。", who->name()); 

		if(who == me)	
			return notify_fail("你不能攻击自己。");

		if(who->is_busy())
			return notify_fail("对方没空理你。");

		if(me->querymap_temp("biwu"))
		{
			CContainer * env1 = load_room("武陵春风雨楼");
			if(!env1->query("biwu"))
				me->delete_temp("biwu");
		}

		if( userp(who) && who->query_temp("pending/fight")!=me->object_id() ) 
		{
			message_vision(snprintf(msg, 255, "$N对著$n说道：%s%s，领教%s的高招！",
				query_self(me), me->name(), query_respect(who)),
				me, who);

			me->set_temp("pending/fight", who->object_id());
			return 1;
		}

		if( who->query("can_speak") ) 
		{
			message_vision(snprintf(msg, 255, "$N对著$n说道：%s%s，领教%s的高招！",
				query_self(me), me->name(), query_respect(who)),
				me, who);

			notify_fail("看起来%s并不想跟你较量。", who->name());
			if( who->Query(CChar::IS_NPC) && ! ((CNpc *)who)->accept_fight(me) ) return 0;

			snprintf(msg, 255, "%s与%s的比试", me->name(), who->name());
			Do_BiShi(me, who, msg, 50);
		} 
		else 
		{
			message_vision("$N大喝一声，开始对$n发动攻击！", me, who);
			who->kill_ob(me);
		}

		return 1;
	}

	DEFINECMD(Follow)
	{
		//禁止在设置为no_follow的场景使用Follow命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_follow")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止跟随他人。");

		CChar * who;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要跟随谁？");

		if(who == me)
		{
			me->set_leader(0);
			tell_object(me, "取消跟随！");
			return 1;
		}

		me->set_leader(who);
		message_vision("$YEL$N决定开始跟随$n一起行动。", me, who);
		return 1;
	}

	DEFINECMD(Say)
	{
		CChar * who;
		char msg[512], names[40];

		if (!strlen(arg)) 
		{
			message_vision("$HIC$N自言自语不知道在说些什么。", me);
			return 1;
		}

		if(!g_Channel.check_channel_msg(me, "say", arg, 0))
			return 0;
		
		//禁止在设置为no_say的场景使用Say命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_say")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止说话。");

		if(me->query("no_say")||me->query_temp("no_say"))
			return notify_fail("由于发送了大量信息，你的说话权利被禁止了。");

		who = GetRoomChar(me, target);
		if(!who || who == me)
			strcpy(names, "$HIC$N说道：");
		else
			strcpy(names, "$HIC$N对$n说道：");
		
		if( me->query("hp") < me->query("max_hp") / 5 ) 
		{
			replace_string(arg, " ", " ... ", 400);
			snprintf(msg, 512, "%s%s ...", names, arg);
		}
		else
			snprintf(msg, 512, "%s%s", names, arg);

		if(me == who)
			message_vision(msg, me);
		else
		{
			message_vision(msg, me, who);

			//who对say作出反应
			if(who)	who->relay_say(me, arg);
		}
		
		return 1;
	}

	DEFINECMD(Halt)
	{
		char msg[255];

		if((me->environment())->Query(CChar::IS_FIGHTROOM))
		{
			CFightRoom * env = (CFightRoom *)me->environment();
			if (me->is_fighting()) 
			{
				if(env->query("room_locked") & FIGHT_NO_FLEE)	//被锁死
					return notify_fail("该战斗被锁住，无法逃脱。");					
				

				if(env->is_bishi())
				{
					message_vision("$N身形向后一跃，跳出战圈不打了。", me); 
					env->End_Fight();
				}
				else 
				{
					//busy中不能逃跑
					if(me->is_busy()) return notify_fail("你没空逃跑！");

					if(! CheckAP(50, me)) return 0;
					if(env->Do_Flee(me))
						ResumeAP(50, me);
				}
				//if(me->query_temp("biwu")) 
				//shout(WHT"【江湖传闻】"+me->name()+"中途放弃比武！\n" NOR);
			}
			else	//观战
			{
				me->move(env->environment());
				tell_room(env, snprintf(msg, 255, "%s停止观战。", me->name()));			
				message_vision(snprintf(msg, 255, "$N离开了%s。", env->name()), me);
			}

			return 1;
		}
		else if (!me->is_busy()) 
			return notify_fail("你现在不忙。");
		
		me->interrupt_me(me, "halt");
		return 1;
	}

	DEFINECMD(Look)
	{
		CContainer * who;

		if(target)
		{
			if(! (who = GetRoomObject(me, target))
				&& !( who = GetSelfObject(me, target)) )
				return notify_fail("你要观察什么？");
		}
		else
			who = me->environment();

		if(! who->do_look(me))
			who->SendMenu(me);

		return 1;
	}

	DEFINECMD(MakeLove)		//不开放的指令。含色情成分。呵呵。
	{
		CChar * who;

		//开放开关
		if(! g_Combatd.query("makelove")) return 0;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你想和谁做爱？\n");

        if( EQUALSTR(me->querystr("gender"), who->querystr("gender")) )
            return notify_fail("这样...？！恐怕不行吧？");

        if(!living(who))
            return notify_fail("人家都这样了，你还...");

		if( me->is_busy() )
			return notify_fail("( 你上一个动作还没有完成。)");
	
        if( EQUALSTR(me->querystr("gender"), "无性") )
            return notify_fail("你一个太监，也想干那事啊？？那不是搞笑吗？");

		CContainer * env = me->environment();
		if( ! env || ! env->query("sleep_room"))
            return notify_fail("总得找个温馨点儿的地方吧。");

		//检查是否有旁观者
		DTItemList * list = env->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		while(p)
		{
			CContainer * obj = list->GetNext(p);
			if( obj->is_character() && obj !=me
                  && obj != who && ! wizardp((CChar *)obj) )
                      return notify_fail("这儿还有别人呢，多不好意思呀！");
		}

		char msg[255];

        if(!me->query_temp("makelove/quest")) 
		{
            if( EQUALSTR(me->querystr("gender"), "男性") ) 
			{
                 message_vision("$YEL$N轻轻的注视着$n，双手搂在$n的小蛮腰，\n轻柔的吻着$n的小耳垂....\n", me, who);
                 tell_object(who, snprintf(msg, 255, "$HIR看起来他想和你共度良宵，\n如果你愿意，请你也对%s下一次 makelove 指令。\n", me->name()) );
            }
            else 
			{
                 message_vision("$YEL$N的小脸儿红扑扑的，缠上来勾住$n的脖子，胸前紧紧的贴着$n的\n胸膛，小嘴嘟嘟的凑上来轻轻的吻着$n的嘴唇....\n", me, who);
                 tell_object(who, snprintf(msg, 255, "$HIR傻子也能看出来她想和你共渡良宵，\n如果你愿意，请你也对%s下一次 makelove 指令。\n", me->name()) );
            }
            
			who->set_temp("makelove/quest",1);
        }
        else 
		{
             if( EQUALSTR(me->querystr("gender"), "男性") ) 
			 {
                  message_vision("$YEL$N过了好半响，实在受不了$n的挑逗\n突然一把将$n紧紧抱住压在床上....\n", me, who);
                  me->call_out(over, 1, target);
             }
             else 
			 {
                  message_vision("$YEL$N极力的忍受着$n火热的挑逗，心头小鹿撞击不停，\n终于瘫软在$n的怀里，被$n一把横抱了起来，轻柔的放在床上....\n", me, who);
                  who->call_out(over, 3, me->object_id());
             }

			 me->start_busy(3);
			 who->start_busy(3);
                
			 me->delete_temp("makelove/quest");			 
        }

        return 1;
	}

	static void over(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

        message_vision("$HIB...屋里的$HIR红烛$HIB被吹灭了...\n", me);
        if(me->query("hp") < 30 || who->query("hp") < 30 )
        {
            if(me->query("hp") < 30 ) 
			{
                 message_vision("$HIR$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。\n", me);
                 me->unconcious();
                 me->add("makeloved",1);
                 who->add("makeloved",1);
             }
             else 
			 {
                 message_vision("$HIR$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。\n", who);
                 who->unconcious();
                 who->add("makeloved",1);
                 me->add("makeloved",1);
             }
        }
        else
		{
			switch(random(10)) 
			{
                case 0:
				        message_vision("$HIR$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n", me);
                        me->unconcious();
                        who->add("hp", who->query_str() - 55 + random(10));
                        who->add("makeloved",1);
                        me->add("makeloved",1);
                        break;
                case 1:
                        message_vision("$HIR$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n", who);
                        who->unconcious();
                        me->add("hp", who->query_str() - 55 + random(10));
                        who->add("makeloved",1);
                        me->add("makeloved",1);
                        break;
                default:
                        if(random(10) > 7) 
						{
                                message_vision("$YEL$N坐在一旁闷头不语，望了一眼仍在微微娇喘的$n，\n喃喃说到：要不然...再让我试一次...\n", me, who);
								who->add("makeloved",1);
								me->add("makeloved",1);
                        }
                        else 
						{
                                message_vision("$HIM$n闭上眼睛静静地躺在床上，感到自己身上的衣服\n一件一件的被脱掉，突然$n感到$N火烫的身体压上了自己...\n", me, who);
                                me->call_out(over1, 3, param1);
                        }
						
						who->add("hp", who->query_str() - 55 + random(10));
						who->add("makeloved",1);
						me->add("hp", who->query_str() - 55 + random(10));
						me->add("makeloved",1);                
			}
		}

		me->start_busy(3);
		who->start_busy(3);
	}

	static void over1(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);
		if(! who) return;

         message_vision("$HIR$N轻柔的吻者$n的唇，手掌开始不安分的抚摸$n光\n滑如缎子般的肌肤，$n娇喘吁吁，双手主动的抱住$N...\n", ob, who);
		 me->call_out(over2, 3, param1);

		 me->start_busy(3);
		 who->start_busy(3);
	}

	static void over2(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

         message_vision("$WHT$N也越来越兴奋，终于和$n结为一体，只听$n\n如蚊子般的“恩。。”了一声，似是痛苦，似是舒服...\n", ob, who);
         me->call_out(over3, 3, param1);

		 me->start_busy(3);
		 who->start_busy(3);
	}

	static void over3(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

         message_vision("$HIW$N的动作越来越快，越来越猛，$n则配合着$N的节奏\n释放出对$N的爱，阵阵呻吟,春光熠熠，春潮绵绵...\n", ob, who);
         me->call_out(over4, 3, param1);

		 me->start_busy(3);
		 who->start_busy(3);
	}

	static void over4(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

        message_vision("$HIM汹涌澎湃的高潮过后，$n温顺的躺在$N的怀里，听着\n$N的心跳声，$N轻轻的抚弄着$n光滑的皮肤，无限温柔...\n", ob, who);
        who->add("hp", who->query_str() - 55 + random(10));
        who->add("makeloved",1);
        me->add("hp", who->query_str() - 55 + random(10));
        me->add("makeloved",1);

		me->start_busy(3);
		who->start_busy(3);
	}
			
	typedef int (* func)(CChar *  me, LONG target, char * arg);
	typedef map<string, func, less<string> > CMDMAP;
	CMDMAP m_StandardCmd;

};


