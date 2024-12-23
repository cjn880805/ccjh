
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

    message_vision("$Nһ����������������ػ��һ�½�ǡ�", me);
	me->delete_temp("block_msg/all");
	tell_object(me, "��һ��������ֻ���������档�ûһ���ˡ�");	
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
		m_StandardCmd["guard"] = Guard;		//��ս
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
		m_StandardCmd["practice"] = Practice;		//�����������ϰ
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

	//ʰȡ get sth. from sth. num
	DEFINECMD(Get)
	{
		char cmd[255], szEnv[40], szNum[40];
		CContainer * who, * env, * obj = NULL;
		LONG num = 0;
		int ap = 30;
		CMapping * m;

		if( me->is_busy() )
			return notify_fail("����һ��������û����ɣ�");

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
			return notify_fail("�����ս����Ķ���������̫Σ���ˣ�����ԥ��һ�£��������ˡ�");

		if(living(env) && (me->query("grant") < 70 || wiz_level(me) <= wiz_level((CChar *)env) ))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������");

		who = env->Present(target);

		if( ! CheckAP(ap, me))
			return 0;

		if(! who || ! who->Query(CChar::CAN_GET))
			return notify_fail("��Ҫ��ʲô��");

		m = who->query_entire_dbase();
		if(! m->undefinedp("no_get") && !(wizardp(me) && me->query("env/override")) )
		{
			strncpy(cmd, who->querystr("no_get"), 255);
			return notify_fail(cmd[0] ? cmd : "��������ò�������");
		}

		//�ж��Ƿ�����
		if( ! m->undefinedp("owner") && !(wizardp(me) && me->query("env/override"))
			&& DIFFERSTR(who->querystr("owner"), me->querystr("id")) )
			return notify_fail("�ⲻ����Ķ�����");

		if(num && who->Query(CChar::IS_ITEM) )
		{
			obj = ((CItem *)who)->Split(num);
		}
	
		if(! obj)
		{
			obj = who;
			num = who->Query_Amount();
		}
		
		snprintf(cmd, 255, "%sʰ������%ld��%s��", me->name(), 
			num, obj->name(), env->name());
		
		if( obj->move(me))
			MessageVision(me, "chat", cmd);
		else
		{
			notify_fail("�������޷�������");
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

	//ʹ����Ʒ
	DEFINECMD(Use)
	{
		CContainer * who;
		CContainer * obj = me;

		//��ֹ������Ϊno_use�ĳ���ʹ��use���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_use")||env->query("no_all"))&& userp(me) )
			return notify_fail("�����ֹʹ�õ��ߡ�");

		char szTarget[40];
		
		if( me->is_busy() )
			return notify_fail("����һ��������û����ɣ�");

		int ap = 50;
		if(! (who = GetSelfObject(me, target)) ) return 0;

		if(strlen(arg))
		{
			analyse_string(arg, szTarget, 40);
			if( ! (obj = GetRoomObject(me, atol(szTarget)) )
				&& ! (obj = GetSelfObject(me, atol(szTarget)) ) )
				return notify_fail("��Ҫ��˭ʹ�ã�");
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

	//װ��
	DEFINECMD(Wield)
	{
		char cmd[80];
		int ap = 25;
		CContainer * who;

		if( ! (who = GetSelfObject(me, target)) ) return 0;

		//��ֹ������Ϊno_wield�ĳ���ʹ��wield���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_wield")||env->query("no_all"))&& userp(me))
			return notify_fail("�����ֹװ�����ߡ�");

		if(me->is_busy())
			return notify_fail("����æ��");

		notify_fail("���޷�װ������������");
		if(who->Query(CChar::CAN_EQUIPPED) && CheckAP(ap, me) && who->Do_Action(CChar::DO_WIELD))
		{
			strncpy(cmd, who->querystr("wield_msg"), 80);
			if(! strlen(cmd))
			{
				strncpy(cmd, who->querystr("wear_msg"), 80);
				if( ! strlen(cmd))
					strcpy(cmd, "$Nװ��$n��");
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

	//ж��
	DEFINECMD(UnWield)
	{
		char cmd[80];
		int ap = 25;
		CContainer * who;

		//��ֹ������Ϊno_unwield�ĳ���ʹ��unwield���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_unwield")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹж�µ��ߡ�");

		if(me->is_busy())
			return notify_fail("����æ�š�");

		if( strcmp(arg, "all") == 0)	//�޲�����ʾȫ��ж��
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
						strcpy(cmd,  "$N�������е�$n��");
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
					strcpy(cmd,  "$N�������е�$n��");
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

		//��λ
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
				message_vision(snprintf(msg, 255, "$N��$n�ӱ��Ϸ�������������%s�", env->name()), me, obj);				
			}
			else 
			{
				message_vision( snprintf(msg, 255, "$N��%s�ﶪ������%ld��$n��", env->name(), amount ), me, obj );
				if( ! obj->query("value") ) 
				{
					tell_object(me, "��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�");
					DESTRUCT_OB(obj, "cmd::drop");
				}
			}
			return 1;
		}
		return 0;
	}

	//������Ʒ drop x y sth. to sth. num
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

		//��ֹ������Ϊno_drop�ĳ���ʹ��Drop���� �ز� 2002-10-09
		if((env->query("no_drop")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ������Ʒ��");
	
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

		if(! x || ! y)	//�����꣬�ö����ߵ�Ŀ������
		{
			x = me->query_temp("map/ex");
			y = me->query_temp("map/ey");
		}

		m = who->query_entire_dbase();
		if(! m->undefinedp("no_drop"))
		{
			const char * ptr = m->querystr("no_drop");
			return notify_fail(ptr[0] ? ptr : "���������������ⶪ����");
		}

		if(me->is_busy())
			return notify_fail("����æ�š�");

		//�жϷ������Ƿ�������
		DTItemList * list = env->Get_ItemList();
		if(list->GetCount() >= env->query("max_items"))
			return notify_fail("%s���Ѿ���ӵ���ˡ�", env->name());

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
				return notify_fail("�ռ�̫С�������޷����ɡ�");
		}

		if(! do_drop(me, obj, env, x, y))
		{
			//�Ѷ����ٻ������ˡ�
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
            return notify_fail("��ĸ��ɹ��أ��������á�");

        if( me->is_busy() )
            return notify_fail("��Ķ�����û����ɣ������ƶ���");

        if( me->query_temp("no_move") )
                return notify_fail("�����ڲ����ƶ���");

        return 1;
	}

	//����
	DEFINECMD(GoDoor)
	{
		CContainer * env = me->environment();//, *obj;
		CDoor * door;
		char msg[255];

		if(! valid_move(me)) return 0;

		notify_fail("��Ҫ���ĸ������ߣ�");
		if(! env->Query(CChar::IS_ROOM)) return 0;
	
		//����ǳ���ж�һ�������Ƿ���һ�����䡣�����������ת�޸����ˡ�
		me = FindMaster(me);
	
		door = ((CRoom *)env)->PresentDoor(arg);
		if(! door) return 0;

		if( !((CRoom *)env)->valid_leave(me, door->querystr("id")) ) return 0;

		if(door->Enter_Door(me) )
		{
			snprintf(msg, 255, "%s��%s�뿪��", me->name(), door->name(1) );
			MessageVision(env, "room", msg);

			snprintf(msg, 255, "%s���˹�����", me->name());
			MessageVision(me, "chat", msg, me);

			me->delete_temp("pending");

			//�ɻ����ڵ��������
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
				if(obj->environment() != env) continue;	//�Ѿ��ƶ�
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
			return notify_fail("�Է�����Ը��������Ķ�����");

		LONG objid = obj->object_id();
		snprintf(cmd, 255, "$N��$n����%ld��%s��", obj->Query_Amount(), obj->name());

		if(who->Query(CChar::IS_NPC) && ! who->Query(CChar::IS_SPRITE))
		{
			if(! ((CNpc *)who)->accept_object(me, obj) ) 
			{
				return notify_fail("�Է���Ҫ��Ķ�����");
			}
		}

		message_vision(cmd, me, who);

		if(g_LastDestructObject == objid)	//�Ѿ�������
		{
			me->Save();
			return 1;
		}
			
		/*if( !userp(who) && obj->query("value")) //NPC ����Ѷ������ţ�����ACCEPT��ֱ�Ӱ�������١�
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

	//�� give sth. to sb. num
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

		if(me->is_busy())	return notify_fail("����æ�š�");

		if(! living(Target)) return notify_fail("�Է�û�취����������");
		
		if(! CheckAP(ap, me)) return 0;

		if(! nNum) nNum = 1;
	
		if( ! (who = GetSelfObject(me, target)) ) return 0;

		if( who->Query(CChar::IS_USER))
			 return notify_fail("���ˣ����кξ��ģ�");

		CMapping * m = who->query_entire_dbase();
		if(! m->undefinedp("no_give") && !(wizardp(me) && me->query("env/override")))
		{
			const char * ptr = m->querystr("no_give");
			return notify_fail(ptr[0] ? ptr : "������������������ˡ�");
		}

		if(! m->undefinedp("no_drop") && !(wizardp(me) && me->query("env/override")))
			return notify_fail("�����������������ˡ�");

		//�ж��Ƿ�����
		if( ! m->undefinedp("owner") && !(wizardp(me) && me->query("env/override"))
			&& DIFFERSTR(who->querystr("owner"), Target->querystr("id")))
			return notify_fail("�ⲻ��%s�Ķ�����", Target->name(1));

		if( ! m->undefinedp("obj") && !(wizardp(me) && me->query("env/override"))
			&& DIFFERSTR(who->querystr("obj"), Target->querystr("id")))
			return notify_fail("�ⲻ��%s�Ķ�����", Target->name(1));
	
		if( who->Query(CChar::IS_ITEM) )
		{
			obj = ((CItem *)who)->Split(nNum);			
		}

		if(! obj) obj = who;
		if(! Do_Give(me, obj, Target))
		{
			//�Ѷ����ٻ������ˡ�
			if(obj->environment() != me)
				obj->move(me);
			return 0;
		}
	
		ResumeAP(ap, me);
		return 1;
	}

	//��ʦ
	DEFINECMD(Apprentice)
	{
		CChar * who;
		char msg[255];

		if(! (who = GetRoomChar(me, target))) return 0;

		//��ֹ������Ϊno_apprentice�ĳ���ʹ��Apprentice���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_apprentice")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ��ʦ��");

		me = FindMaster(me);
		who = FindMaster(who);

		if( ! who->Query(CChar::IS_LIVING) )
		{
			return notify_fail("������Ȱ�%sŪ�ѡ�", who->name());
		}

		if( who==me ) 
			return notify_fail("���Լ�Ϊʦ�������⣮����P");
	
		if( me->is_apprentice_of(who) ) 
		{
			message_vision("$N������������$n��ͷ�밲���е�����ʦ������", me, who);
			return 1;
		}

		const char * bangpai = me->querystr("family/family_name");
		if ( bangpai[0] && DIFFERSTR(bangpai, who->querystr("family/family_name")) )
			return notify_fail("δ������ʦ��ͬ�ⲻ�ܸĻ����ɣ�");
		
		if (EQUALSTR(who->querystr("family/master_id"), me->querystr("id")))
			return notify_fail("��ʲô��Ц�����Լ���ͽ��Ϊʦ��");
			
		// If the target is willing to recruit us already, we do it.
		if( who->query_temp("pending/recruit") == me->object_id()) 
		{
			if( EQUALSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
			{
				message_vision("$N����Ͷ��$n���£���$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������", me, who);
				me->set("score", 0L);
			} 
			else
				message_vision("$N������$nΪʦ��$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������", me, who);
				    
			who->recruit_apprentice(me);
			who->delete_temp("pending/recruit");

			tell_object(who, "��ϲ��������һ�����ӣ�");
			tell_object(me, snprintf(msg, 255, "��ϲ����Ϊ%s�ĵ�%ld�����ӡ�",  me->querystr("family/family_name"), me->query("family/generation")));
				
			return 1;
   		} 

		tell_object(me, snprintf(msg, 255, "����Ҫ��%sΪʦ��",	who->name()) );
		me->set_temp("pending/apprentice", who->object_id());
		if( who->Query(CChar::IS_USER))
		{
			tell_object(who, snprintf(msg, 255, "�����Ը����%sΪ���ӣ������佻̸��", me->name()));
			
			//��Ϊ�˵����͡� 1.7�� lanwood 2001-03-24
			//ע�⣬������$1������me����Ϊ�Է�δ��ѡ����Ϊ��ǰĿ�ꡣ
			/*
			char tmp[40];

			me->AddMenuItem(snprintf(msg, 80, "��%sΪͽ", me->name()), 
				snprintf(tmp, 40, "$0recruit %ld", me->object_id()), who);
			me->AddMenuItem("�뿪", "", who);
			me->SendMenu(who);
			*/
		}
		else 
			who->attempt_apprentice(me);
   
		return 1;
	}

	//��ͽ
	DEFINECMD(Recruit)
	{
		char msg[255];
		CChar * who;

		if(! (who = GetRoomChar(me, target))) return 0;

		//��ֹ������Ϊno_recruit�ĳ���ʹ��Recruit���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_recruit")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ��ͽ��");

		me = FindMaster(me);
		who = FindMaster(who);

		if( who == me )
			return notify_fail("���Լ�Ϊ���ӣ������⣮��������û���á�");

		if( who->is_apprentice_of(me) )
		{
			message_vision("$N����$n��ͷ��˵��������ͽ������", me, who);
			return 1;
		}


		if(! me->querystr("family/family_name")[0])
			return notify_fail("�㲢�������κΰ��ɣ�������ȼ���һ�����ɣ����Լ���һ��������ͽ��");
		
		if(! me->query("family/generation"))
			return notify_fail("������ͽ��������һλ����ʦ������������ǽ��˵�ɡ�");
		
		const char * bangpai = who->querystr("family/family_name");
		if ( bangpai[0] && DIFFERSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
			return notify_fail("δ����ʦ��ͬ������˼�ǽ�ǲ�̫�ðɡ�");
		
		if ( EQUALSTR(me->querystr("family/master_id"), who->querystr("id")) )
			return notify_fail("��ʲô��Ц���˼�����ʦ��������ʲôҪ��������ѧ�ģ�");
	
		//begin----- �����ͽ������ lanwood 2001-02-25

		//���������ŵ�ʱ�򣬻��Զ��������ž���Ϊ50
		int count = 0;
		if(userp(me) && (count = me->recruit_num()) >= me->query("recruit_exp") / 50) 
			return notify_fail("������ͽ��%ld�ˡ���������ž��鲻������ͽ��", count);
		
		//end-------

		// If the target is willing to apprentice us already, we do it.
		if( who->query_temp("pending/apprentice") == me->object_id())
		{
			if(! who->Query(CChar::IS_LIVING))
			{
				message_vision("$N������$nΪ���ӡ�����������$n��Ȼû�а취�а�ʦ֮��", me, who);
				return 1;
			}
        
			// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
			if(who->querystr("family/family_name")[0] && DIFFERSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
			{
				message_vision("$N����Ͷ��$n���£���\n$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������", me, who);
				who->set("score", 0L);
			} 
			else
			{
				message_vision("$N������$nΪ���ӡ�\n$n����������$N���������ؿ����ĸ���ͷ���е�����ʦ������", me, who);          
			}
		
			me->recruit_apprentice(who);
			who->delete_temp("pending/apprentice");

			tell_object(me, "��ϲ��������һ�����ӣ�");
			tell_object(who, snprintf(msg, 255, "��ϲ����Ϊ%s�ĵ�%ld�����ӡ�", who->querystr("family/family_name"), who->query("family/generation")) );
			return 1;
		} 

		me->set_temp("pending/recruit", who->object_id());
		message_vision("$N��Ҫ��$nΪ���ӡ�", me, who);
		
		tell_object(who, snprintf(msg, 255, "�����Ը���%sΪʦ���������佻̸��", me->name()));
		
		/*//��Ϊ�˵�ָ�1��7�� lanwood 2001-03-24
		char tmp[40];

		me->AddMenuItem(snprintf(msg, 255, "��%sΪʦ", me->name()), 
			snprintf(tmp, 40, "$0apprentice %ld", me->object_id()), who);
		me->AddMenuItem("�뿪", "", who);
		me->SendMenu(who);
		*/

		return 1;
	}

	//���ʦ��
	DEFINECMD(Expell)
	{
		char msg[255];
		CChar * who;

		if(! (who = GetRoomChar(me, target))) return 0;

		//��ֹ������Ϊno_expell�ĳ���ʹ��Expell���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_expell")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ��ͽ��");

		if( ! who->Query(CChar::IS_USER))
			return notify_fail("��ֻ�ܿ�����������ݵ����");

		if( me->query("family/privs") == -1
			&&  EQUALSTR(me->querystr("family/family_name"), who->querystr("family/family_name")) )
		{
			message_vision(snprintf(msg, 255, "$N����$n˵�����ӽ���������Ҳ������%s�ĵ����ˣ����߰ɣ�", me->querystr("family/family_name")), me, who);
			tell_object(who, "�㱻�����ʦ���ˣ�");
		} 
		else if( (who)->is_apprentice_of(me) ) 
		{
			message_vision("$N����$n˵�����ӽ���������ʦͽ������������߰ɣ������粨���ƶ����Σ�����Ϊ֮������", me, who);
			tell_object(who, "�㱻ʦ�������ʦ���ˣ�");
		} 
		else
			return notify_fail("����˲�����ĵ��ӡ�");
	
		char myfamily[80];
		who->release_master();

		me->del("zhangmen");
		who->del("family");
		snprintf(myfamily, 80, "%s��ͽ", who->querystr("family/family_name"));
		who->set("title", myfamily);
		who->UpdateMe();
		who->Save();

		CMapping * skills = who->query_skills();
		
		CVector v;

		skills->keys(v);
		//���м��ܽ�һ��
		for(int i=0; i<v.count(); i++)
		{
			(*skills)[v[i]] /= 2;
		}
	
		return 1;
	}

	DEFINECMD(Teach)
	{
		
		//��ֹ������Ϊno_teach�ĳ���ʹ��Teach���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_teach")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ���ڼ��ܡ�");

		CChar * who;

		if (me->is_busy())
			return notify_fail("��������æ���ء�");
		
		if( me->is_fighting() )
			return notify_fail("����ĥǹ������������");

		if(! me->querymap("couple")) 
			return notify_fail("�㻹û�а����أ�");

		who = (CChar *)(me->environment())->present(me->querystr("couple/id"));

		 if( !who ) 
			 return notify_fail("���%s�������", me->querystr("couple/gender"));			
		
		if( !living(who) )
			return notify_fail("��....����Ȱ�%sŪ����˵��", who->name());

		if(who->is_busy())
			return notify_fail("%s������æ���ء�", who->name());

		if(who->is_fighting() )
			return notify_fail("����ĥǹ������������");

		if(who && me->query("add_skill/count"))
			return notify_fail("����ʱ�޷�ָ������µ��书����");


		if(! strlen(arg))	//�޲�������ʾ���Խ̵ļ���
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

			who->AddMenuItem("�뿪", "", me);
			who->SendMenu(me);

			return 1;
		}

		int my_skill = me->query_skill(arg, 1);

		if( ! my_skill )
			return notify_fail("������㻹�����أ�");

		int student_skill = who->query_skill(arg, 1);

		if( my_skill <= student_skill )
			return notify_fail("�����%s�ĳ̶��Ѿ����������ˡ�", who->name());

		CSkill * sk = load_skill(arg);

		notify_fail("��%sĿǰ��������û�а취ѧϰ���ּ��ܡ�", who->name());
		if( ! sk->valid_learn(who) ) 
		   return 0;

		if(student_skill>351)
			return notify_fail("��İ���ѧϰǱ���Ѿ����ӵ�ͷ�ˣ�����ܻ��ǰ����Լ�ȥ����������������ߵľ���ɡ�");

		//�������Ǽ����ж� lanwood 2001-05-27
		if(! who->can_learn(arg)) return notify_fail("�����%s����������ϰ��", who->name());

		int gin_cost = 100;

		if( !student_skill ) 
		{
			gin_cost *= 2;
			who->set_skill(arg, 0);
		}

		if(me->query("sk_exp") * 3 > me->query("combat_exp"))
			return notify_fail("���Ѿ�û�ж���ļ��ܾ������İ����ˡ�");
		if(who->query("sk_exp") * 3 > who->query("combat_exp"))
			return notify_fail("��İ���ѧϰǱ���Ѿ����ӵ�ͷ�ˡ����ǰ����Է������������ɡ�");
		
		//���ڼ�������ľ���
		LONG need_points =  who->skill_need_points(arg);
		LONG need_exp = need_points / who->learn_bonus() + 1;
		
		//������ҵľ��鹻����
		if(who->query_valid_exp() < need_exp)
			return notify_fail("ѧϰ%s����%ld�㾭�飬%s��Ҫ������������", sk->name(1), need_exp, who->name());
		if(me->query_valid_exp() < need_exp)
			return notify_fail("�̻�%s����%ld�㾭�飬����Ҫ������������", sk->name(1), need_exp);
		
		char msg[255];

		tell_object(me, snprintf(msg, 255, "����%s�����йء�%s�������ʡ�", who->name(), sk->name(1)));

		if( who->query("env/no_learn") )
			return notify_fail("����%s���ڲ���׼������������⡣", who->name());

		tell_object(who, snprintf(msg, 255, "%s��������йء�%s�������⡣", me->name(), sk->name(1)));

		if( me->query("hp") > gin_cost ) 
		{
			if( userp(me) ) me->receive_damage("hp", gin_cost );
		} 
		else 
		{
			tell_object(me, "������̫���ˣ�û�а취�ٽ̡�");
			tell_object(who, snprintf(msg, 255, "����%s��Ȼ̫���ˣ�û�а취����ʲ�ᡣ", me->name()));
			return 1;
		}
			
		if(who->query("hp") > gin_cost )			
		{
			if( strcmp(sk->type(), "martial") == 0 && student_skill > CChar::level2skill(who->query("level")) ) 
			{
				tell_object(who, snprintf(msg, 255, "Ҳ����ȱ��ʵս���飬���%s�Ľ��������޷���ᡣ",  me->name()));
			}
			else
			{ 
				tell_object(who, snprintf(msg, 255, "�����˵�ָ�����ƺ���Щ�ĵá�", me->name()));
             
   				who->add("sk_exp", need_exp);
				me->add("sk_exp", need_exp);

				who->improve_skill(arg, need_points + 1);				
			}

			who->receive_damage("hp", gin_cost);
		}
		else
		{
			tell_object(who, "�����̫���ˣ����ʲôҲû��ѧ����");
		}
		
		return 1;
	}

	//��̼��ܡ�
	/*
		Designed by Lanwood 2000-12-23

		ʦ��ָ�㣬һ��һ��������100 HP
		��Ҫ���飺������һ������learned���㡣
		need_points = (skill + 1) * (skill + 1) - learned;
		һ�㾭������ pt = (level / 10 + 1) * int / 3;
		��ô���辭��Ϊ��need_exp = need_points / pt + 1;
	*/

	DEFINECMD(Learn)
	{
		//��ֹ������Ϊno_learn�ĳ���ʹ��Learn���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_learn")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹѧϰ���ܡ�");

		int master_skill, my_skill;
		CChar * who;
		char msg[255];
		
		if (me->is_busy())
			return notify_fail("��������æ���ء�");

		if(! (who = GetRoomChar(me, target)))
			return notify_fail("��Ҫ��˭��̣�");

		if(! strlen(arg)) return notify_fail("ָ���ʽ��learn skill_name");
	
		if( me->is_fighting() )
			return notify_fail("����ĥǹ������������");

		if(! who->Query(CChar::IS_LIVING) )
			return notify_fail("�ţ���������ȰѶԷ�Ū����˵��");

	//	if( !me->is_apprentice_of(who) )
	//		return notify_fail("�Է���Ȼ��Ը���㡣");

		if( ! me->is_apprentice_of(who) && !(who->recognize_apprentice(me)) )
		{
			who->say("����Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��", me);
			who->SendMenu(me);
			return 0;
		}

		if( who->is_fighting())
			return notify_fail("���ʦ����ʱû��ָ�����书��");

		if( ! (master_skill = who->query_skill(arg, 1)) )
			return notify_fail("���������±����ұ���ѧ�ˡ�");
	
		if( who->prevent_learn(me, arg) )
			return notify_fail("��Ȼ�Է���Ը��������ܡ�");

		if(who && who->query("add_skill/count"))
			return notify_fail("���ʦ����ʱû��ָ�����书����");

		my_skill = me->query_skill(arg, 1);
	
		if( my_skill >= master_skill )
			return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�");

		CSkill * sk = load_skill(arg);
		if(! sk) return notify_fail("���޷�ѧϰ����ܡ�");
   
		notify_fail("���޷�ѧϰ����ܡ�");
		if( !sk->valid_learn(me) ) return 0;

		//�������Ǽ����ж� lanwood 2001-05-27
		if(! me->can_learn(arg)) return notify_fail("�����������������ϰ��");

		if( who->query("env/no_teach") )
		{
			who->say("����������⣬�Ժ���˵�ɡ�");
			who->SendMenu(me);
			return 0;
		}
		if( who->query(snprintf(msg, 255, "env/%s",arg)) )
		{
			who->say("�����书������ʦ����������㡣");
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
				who->say("ͽ������������Ҳ��һ����ʦ�ˣ�����ܻ������Լ�ȥ����������������ߵľ���ɡ�");
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
					who->say("ͽ��������ʦ���ҽ���̫���ˣ�������˵�ɡ�", me);
					who->SendMenu(me);
					return 1;
				}
			}
		}

		if(me->query("hp") < 100) return notify_fail("�����̫���ˣ����ʲôҲû��ѧ����");

		//��ҵļ��ܾ������ܾ����еı��ز��ܳ���1/3
		if(me->query("sk_exp") * 3 > me->query("combat_exp"))
		{
			who->say("ϰ������ʵ�����ҿ��㻹��Ŭ�����һ���������ʰɡ�", me);
			who->SendMenu(me);
			return 1;
		}			

		//���ڼ�������ľ���
		LONG need_points =  me->skill_need_points(arg);
		LONG need_exp = need_points / me->learn_bonus() + 1;
		
		//������ҵľ��鹻����
		if(me->query_valid_exp() < need_exp)
		{
			who->say(snprintf(msg, 255, "ѧϰ%s����%ld�㾭�飬����ȥ���������ɡ�", sk->name(1), need_exp), me);
			who->SendMenu(me);
			return 1;
		}
	    
		//������ҵļ��������з�ﵽ
		if( strcmp(sk->type(), "martial") == 0 &&
			my_skill >= CChar::level2skill(me->query("level")) ) 
		{
			who->say(snprintf(msg, 255, "��ȱ��ʵս���飬�޷����%s��", sk->name(1)), me );
			who->SendMenu(me);
			return 1;
		}

		me->add("sk_exp", need_exp);
		me->improve_skill(arg, need_points + 1);
		me->receive_damage("hp", 100);

		me->FlushMyInfo();
		//message_vision("$N����$n��ָ�����ƺ���Щ�ĵá�", me, who);
		return 1;
		//
	}
	
	DEFINECMD(Abandon)
	{
		CMapping * smap;
		CSkill * sk;
		char msg[255];
	
		if(!me->query_temp("validate"))
			return notify_fail("����ʹ�� </validate ������� ��İ���> ������֤�����ݺ󷽿ɷ�����ļ��ܡ�");

		if(! strlen(arg)) 
			return notify_fail("��Ҫ������һ��ܣ�");

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
			return notify_fail("�㲢û��ѧ������ܡ�");

		if(! (sk  = load_skill(arg)) )
			return notify_fail("û������ܡ�");

		me->say(snprintf(msg, 255, "�������������ѧϰ%s��", sk->name(1)), me);
		me->SendMenu(me);

		//д����־
		output_error("%s(%s)����%ld��%s��From(%s)", me->name(1), me->id(1), lvl, arg, GetIP(me));

		me->FlushMySkill(me);
		return 1;
	}

	DEFINECMD(Enforce)
	{
		int pts;

		if( ! strlen(arg) ) 
			return notify_fail("ָ���ʽ��enforce <ʹ�����������˵�>");

		if( ! strlen(me->query_skill_mapped("force")) )
			return notify_fail("������� enable һ���ڹ���");

		pts = atoi(arg);

		if(! pts )
			me->del("mp_factor");
		else 
		{
			if( pts < 0 || pts > me->query_skill("force") / 2 )
				return notify_fail("��ֻ����0��ʾ���������������ֱ�ʾÿһ���ü���������");
			me->set("mp_factor", pts);
		}

		tell_object(me, "Ok.");
		me->SendState(me);
		return 1;
	}

	DEFINECMD(Kill)	//�ǳ��
	{
		CChar * who;
		CContainer * env=me->environment();

		if(! (who = GetRoomChar(me, target)) ) return 0;

		if(userp(me) && userp(who) && ! me->querymap("freedom"))
		{
			//if( !me->querymap("corps"))
			//	return notify_fail("�����������֯����ȨPK��");
			if(! who->querymap("corps") && ! who->query("pks") )
			{
				if(who->query_temp("���ɴ���/online"))
				{
					if(((CChar *)env)->Query(CChar::IS_USER))
					{
						env=env->environment();
					}
					if(EQUALSTR(env->querystr("base_name"),"fight_room"))
					{
						env=env->environment();
					}
					if(!env->query("���ɴ���"))
						return notify_fail("���ܶ��޹�����ʹ��ɱ�֡�");
					else
						env=me->environment();
				}
				else
					return notify_fail("���ܶ��޹�����ʹ��ɱ�֡�");
			}
			if(who->query_temp("���ɴ���/online"))
			{
				if(((CChar *)env)->Query(CChar::IS_USER))
				{
					env=env->environment();
				}
				if(EQUALSTR(env->querystr("base_name"),"fight_room"))
				{
					env=env->environment();
				}
				if(env->query("���ɴ���") && EQUALSTR(me->querystr("family/family_name"),who->querystr("family/family_name")))
					return notify_fail("���ɴ����ڼ䣬���ö�ͬ�Ű���ɱ�֡�");
				else
					env=me->environment();
			}

			if(who->query_temp("fight/is_fighting"))
			{
				return notify_fail("�����ڹ�ս�а���͵Ϯ��");
			}
			if(who->query_temp("����"))
			{
				return notify_fail("�㿴���ڶ�������ִ�ӵ����һ�ԣ���һ�����������֡�");
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

					CContainer * obj = Do_BiShi(me, who, "��������ֳ�", -1);
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
					CContainer * env1 = load_room("���괺����¥");
					if(!env1->query("biwu"))
						me->delete_temp("biwu");
				}
				me->set_killer(who);
				who->set_killer(me);
				if(load_room("pk")->query("PK����"))
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
							if(!load_room("pk")->query("PK����"))
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
						if(!load_room("pk")->query("PK����"))
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
			return notify_fail("����һ��������û����ɣ�����ʩ����");

		if(( (me->environment())->query("no_cast")||(me->environment())->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹʹ�÷�����");

		if(me->query_temp("no_cast"))
			return notify_fail("�㲻������ʹ�÷���!");

		analyse_string(arg, magic, 40);
		
		//�жϽ�ɫ�Ƿ����ոü��ܡ�
		skill = arg;
		if(me->query_skill(skill, 1) < 1) 
			return notify_fail("�㻹�������ּ��ܣ�");

		sk = load_skill(skill);

		//Ҳ�����⣬���������"special"���Ϳ��Բ�װ��ֱ��ʹ�á�		
		if(! sk->query("special"))
		{
			skill = me->query_skill_mapped(arg);
			
			if(! strlen(skill))
			{
				return notify_fail("����׼�����ܡ�");
			}
		
			sk = load_skill(skill);

			char valid_types[7][10] = {"unarmed", "finger", "hand", "cuff", "claw", "strike","leg"};
			CContainer * weapon = me->query_weapon();

			if(DIFFERSTR(arg, "force"))	//���ڹ�����Ҫ�ж�����
			{
				int bCanUse = 0;
				for(int i=0; i<7; i++)
				{
					if(strcmp(arg, valid_types[i]) == 0)
					{
						//�������
						if(! weapon || DIFFERSTR(weapon->querystr("skill_type"), valid_types[i]) )
							bCanUse = 1;
					}
				}

				if(bCanUse && weapon)
					return notify_fail("�������֣�");

				//if(EQUALSTR(arg, "parry") && weapon)
				//	return notify_fail("ʹ���м��޷����������!");

				if(!bCanUse && (DIFFERSTR(arg, "parry") && DIFFERSTR(arg, "dodge") )
					&& (! weapon || DIFFERSTR(weapon->querystr("skill_type"), arg ) ))
					return notify_fail("ʹ�õ��������ԣ�");
			}
		}
		
		notify_fail("����ʹ�õļ��ܲ�֧�ָ÷�����");
		if(sk->Cast(magic, me, who) )
		{
			//���who �Ƿ����
			if(g_LastDestructObject == target)
				who = 0;

			me->improve_skill(skill, 1 + me->query("level") / 5, 1);

			if(strcmp(magic, "lifeheal") == 0) return 1;
			if(strcmp(magic, "recover") == 0) return 1;
			if(strcmp(magic, "powerup") == 0) return 1;
			if(strcmp(magic, "heal") == 0) return 1;
			if(strcmp(skill, "begging") == 0) return 1;
			if(strcmp(skill, "persuading") == 0) return 1;

			
			//�ж϶����Ƿ�ΪNPC
			if(! who || ! userp(who) || me == who )
			{
				if(DIFFERSTR(skill,"roar")) return 1;
			}

			if(userp(me))
			{
				if(me->querymap_temp("biwu"))
				{
					CContainer * env1 = load_room("���괺����¥");
					if(!env1->query("biwu"))
						me->delete_temp("biwu");
				}
				((CUser *)me)->Ready_PK();
			}

			return 1;
		}

		return 0;
	}

	//����ս�� join 12 1
	DEFINECMD(JoinBattle)
	{
		//��ֹ������Ϊno_join�ĳ���ʹ��JoinBattle���� �ز� 2002-10-09
		if(((me->environment())->query("no_join")||(me->environment())->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ����ս��");

		int team;
		CChar * sprite;
		CFightRoom * obj;
		CContainer * who;
		char msg[512];

		me = FindMaster(me);

		if(me->is_busy())
			return notify_fail("��������æ��");

		//Ҫ����ս������
		if(! (who = GetRoomObject(me, target)) ) return 0;
		if(! who->Query(CChar::IS_FIGHTROOM)) return 0;
		if(! atoi(arg))		//����A��
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

			if(EQUALSTR((me->environment())->querystr("area"),"����") && !obj->query("smash")) 
				return notify_fail("�����Լ��ģ������˵���ʲô!");

			if(!obj->query("smash"))
				return notify_fail("��ս�����ܼ���!");
		
		}
//��ֹ����NPCһ������ս��  �ز�		
		int team_obj=100;
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		CContainer * env = load_room("pk");
		while(p) 
		{ 
			CContainer * obj1 = list->GetNext(p);
			if(! obj1->is_character()) continue; 
			CChar * target = (CChar *)obj1;  
			if(!userp(target)  && !target->query("help") && DIFFERSTR(target->name(1),"��ɽ����") && DIFFERSTR(target->name(1),"���Ʋ���") &&
				!(EQUALSTR(target->id(1),"biao che") && atoi(target->querystr("������"))) &&
				!(env->query("mj/start") && EQUALSTR(target->querystr("family/family_name"), "����")&& !userp(target)))
			{
				team_obj=target->query_temp("fight/fight_team");
				break;
			}
		}
		if(team_obj!=100 && team==team_obj && userp(me) && !obj->query("smash") )
		{
			return notify_fail("��ս����ֹ����NPCһ��!");
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
			
			tell_room(obj, snprintf(msg, 255, "%s����%s.", me->name(), obj->name()));
			tell_room(me->environment(), snprintf(msg, 255, "%s����ս��%d.", me->name(), team));
			
			//PK Mark!
			if(userp(me))
				((CUser *)me)->Ready_PK();
		}
		return 1;
	}
	
	//��ս
	DEFINECMD(Guard)
	{
		CContainer * obj;
		char msg[255];

		if(me->is_busy())
			return notify_fail("��������æ��");

		//Ҫ����ս������
		if(! (obj = GetRoomObject(me, target)) ) return 0;
		if(! obj->Query(CChar::IS_FIGHTROOM)) return 0;
		if(DIFFERSTR(obj->name(1),"��������ֳ�") && DIFFERSTR(obj->name(1),"��������"))
		{
			CMapping * m = obj->query_entire_dbase();
			if(! m->undefinedp("no_guard") && ! wizardp(me) )
			{
				const char * ptr = m->querystr("no_guard");
				return notify_fail(ptr[0] ? ptr : "��ս���������ս!");
			}
			
			int flee = m->query("room_locked");
			if(flee & FIGHT_NO_JOIN) return notify_fail("��ս������ס���޷���ս��");
		}
	
		me->move(obj);					
		message_vision("$N�����ս��", me);
		tell_room(obj->environment(), snprintf(msg, 255, "%s�ۿ�%s��", me->name(), obj->name()));
		return 1;
	}

	DEFINECMD(Tell)
	{
		//��ֹ������Ϊno_tell�ĳ���ʹ��Tell���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_tell")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ˽�ġ�");


		char msg[512];
		CChar * who;
		
		if(!(who = find_player(target)) ) return notify_fail("û������ˡ�����");

		if(! living(who) || who->query_temp("net_dead"))
			return notify_fail("�Է��������㽲����");
	
		char key[80];
		
		snprintf(key, 80, "notell/%s", me->querystr("id"));

		if (! wizardp(me) && (who->query_temp(key) 
			|| who->query_temp("notell/all")) )
			return notify_fail("%s������������Ļ���", who->name(1)); 	

		if(! g_Channel.check_channel_msg(me, "tell", arg, 0))
			return 0;

		snprintf(msg, 512, "&C=%d&i=%s&n=%s&M=%s&", 
			TELLOBJECT,
			me->querystr("id"),
			me->name(1), arg);
		who->SendCommand(msg, 1);

		tell_object(me, snprintf(msg, 400, "$HIG��˽�ġ������%s��%s", who->name(), arg));

		//�ж϶Է��Ƿ񷢴���
		int idle;
		if(userp(who) && (idle = ((CUser *)who)->query_idle()) > 180)
		{
			tell_object(me, snprintf(msg, 400, "$HIG%s�Ѿ�������%ld�룬���ܲ������ϻش���Ŷ��", who->name(), idle));
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
			return notify_fail("��Ҫ��˭�����ָ�");

		if(who->query_condition("prostitute") < 1)			
			return notify_fail("�Է��ɲ�Ը������Ŷ��");

		if(DIFFERSTR(me->querystr("gender"), "����"))
			return notify_fail("�����������������Ŷ��");

		if(me->query("hp") < 1000 )
			return notify_fail("�����������������Ŷ��");
		
		LONG value = who->query("value") / 3;	//���
		if(! CMoney::Player_Pay(me, value))
			return notify_fail("%s���%ld����������ɬ������֧������", who->name(), value);
		
		message_vision(snprintf(msg, 255, "\n\n$HIY$N��$n����һЦ����������������������%s���棡", query_self_rude(me)), me, who);
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

		//�жϳɹ���
		int caiqi = who->query_skill("literate", 1) + who->query_skill("music", 1);
		int succ = me->query_skill("literate", 1) + who->query_skill("music", 1);
		if(random(succ + caiqi) < caiqi)	//���ղ�����
		{
			message_vision("$HIY\n\n$n������£�Ϊ$N����һ֧���ӡ�\n���ϣ�$n��$N΢΢һ������Բ���СŮ�����ղ�����", me, who);			
		}
		else
		{
			if(who->query_temp("selled"))
				message_vision("$HIY\n\n$n���µĿ���$N���������СŮ��������������ү����Ź���һ�ΰɡ�", me, who);
			else
				message_vision("$HIY\n\n$n��Ц�ŵ���$N���У�����������û�~~~~~", me, who);
		
			me->command("unwield 0 all");
			who->command("unwield 0 all");

			message_vision("\n$HIR$N������Ц�ţ�����$n����Ϩ���򡭡�", me, who);
			tell_object(me, snprintf(msg, 255, "$HIY\n\n��§��%s��������壬���ɵ��������ԣ�����\n\n\n", who->name()));
			tell_object(who, snprintf(msg, 255, "$HIY\n\n������%s�Ļ�����ɵ��������ԣ�����\n\n\n", me->name()));
			
			me->set("last_sleep", current_time);
			who->set("last_sleep", current_time);
			me->set_temp("block_msg/all",1);
			who->set_temp("block_msg/all",1);
			message_vision("$HIY $N��$n���뱻�У�§��һ��˯���ˣ�����\n\n\n",me, who);
			
			me->disable_player("˯����");
			who->disable_player("˯����");

			me->call_out(wakeup2, random(45 - me->query_con()) + 10, who->object_id());
			who->call_out(wakeup2, random(45 - who->query_con()) + 10, me->object_id());        

			me->add("wench/sleep", 1);
			who->add("wench/sleep", 1);
		}

		who->add("hp", -450);
		
		//����ҵ��
		me->add("wench/take", 1);	//�Ӵ�����
	}

	//�ı�ָ��
	DEFINECMD(Sleep)
	{
		CContainer * where = me->environment();
   
		if( ! where->query("sleep_room") &&
			! me->query_temp("force_sleep") &&
			DIFFERSTR(me->querystr("family/family_name"), "ؤ��") )
			return notify_fail("���ﲻ��˯���ĵط���");

		if (me->is_busy())
			return notify_fail("����æ���أ�");

		if( me->is_fighting() )
			return notify_fail("ս���в���˯����");

		//if (where->query("hotel") && !(me->query_temp("rent_paid")))
		//{
		//	message_vision("��С���������$N���: �����ﵱ��������! �ȵ�һ¥��Ǯ������˯!",me);
		//	return 1;
		//}
        
		if ( (current_time - me->query("last_sleep") ) < 90 )
			return notify_fail("���˯��һ��, �Ȼ��ɡ� ");
			
		if( ! target || target == me->object_id())
        {
			me->disable_player("˯����");
			int rnd;

			if (where->query("sleep_room"))
			{
				tell_object(me, "��������һ�꣬��ʼ˯����\n��һ�������ͽ��������硣");
				me->set("last_sleep", current_time);
				me->set_temp("block_msg/all", 1);
				message_vision("$N������һ�꣬��һ����������������������硣",me);
				rnd = random((60 - me->query_con()) / 3);
			}
			else
			{ 
				tell_object(me, "��͵�һ�ɣ���ʼ˯����\n��һ�������ͽ��������硣");
				me->set("last_sleep", current_time);
				me->set_temp("block_msg/all",1);
				message_vision("$N�͵�һ�ɣ���һ����������������������硣",me);
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
			return notify_fail("�����˭һ��˯��");
		
		if( ! userp(obj))
			return notify_fail("�˼ҿɲ�Ը���㣡");

 
		//can't sleep with npc...
		
		if(! (EQUALSTR(me->querystr("gender"), "����") && EQUALSTR(obj->querystr("gender"), "Ů��")
			  || EQUALSTR(me->querystr("gender"), "Ů��") && EQUALSTR(obj->querystr("gender"), "����"))  )
			  return notify_fail("����û��˯Ŷ��");

		if( ! obj->Query(CChar::IS_LIVING) )
			return notify_fail("%sû������˯�ˡ�", obj->name()); 

		if (!where->query("sleep_room"))   
			return notify_fail("���������̫�ðɡ�");

		if (obj->is_busy())
			return notify_fail("�Է���æ���أ�");

		if( me->query("hp") * 100 / me->query("max_hp") < 50 )
			return notify_fail("��������������������㡣");

		if(me->querymap("condition") && !me->query_condition("wc_poison"))
			return notify_fail("��ĺ���������ļ����������������ж�������������������������㡣");

		if( obj->querymap("condition") && !obj->query_condition("wc_poison"))
			return notify_fail("�Է��ĺ���������ļ������������Է������������ж�����ʵ����������������㡣");

		if( obj->query_temp("apply/index") )
			return notify_fail("�Է�������ô���룬������Ҫ�������ȥ�İɣ����ڻ��п�˯����");

		if( me->query_temp("apply/index") )
			return notify_fail("�㴩����ô���룬��ȥ�Ͻֻ���Ҫ˯���أ�");

		if( userp(obj) && obj->query_temp("pending/sleep") != me->object_id()) 
		{
			message_vision("\n$RED$N���������ض�$n˵���ң�����\n\n", me, obj);
						
			me->set_temp("pending/sleep", obj->object_id());
			tell_object(obj, snprintf(msg, 255, "$YEL����%s(%s)������㣮���������Ը�⣬�����佻̸��", me->name(), me->id()));
			tell_object(me, "$YEL�Է����ڿ����У�����\n");

			//���Ӳ˵����� lanwood 2001-03-24
			/*	char show[80], tmp[40];

				me->AddMenuItem(snprintf(show, 80, "ͬ���%s˯��", me->name()),
					snprintf(tmp, 40, "$0sleep %ld", me->object_id()), obj);
				me->AddMenuItem("�뿪", "", obj);
				me->SendMenu(obj);
			*/
			return 1;
		}

		message_vision("$RED\n$N����$n���ĵ�һЦ�����˵�ͷ��\n\n", me, obj);
		
		me->command("unwield 0 all");
		obj->command("unwield 0 all");
		//�������װ���ĸ���Ч��  �ز� 2002-10-09
		//me->delete_temp("apply");
		//obj->delete_temp("apply");
		me->UpdateMe();
		obj->UpdateMe();
		
		if(EQUALSTR(me->querystr("gender"), "����"))
		{
			tell_object(me, snprintf(msg, 255, "$HIY\n\n��§��%s��������壬���ɵ��������ԣ�����\n\n\n", obj->name()));
			tell_object(obj, snprintf(msg, 255, "$HIY\n\n������%s�Ļ�����ɵ��������ԣ�����\n\n\n", me->name()));
		}
		else
		{
			tell_object(obj, snprintf(msg, 255, "$HIY \n\n��§��%s��������壬���ɵ��������ԣ�����\n\n\n", me->name()));
			tell_object(me, snprintf(msg, 255, "$HIY\n\n������%s�Ļ�����ɵ��������ԣ�����\n\n\n", obj->name()));
		}
		
		me->set("last_sleep",current_time);
		obj->set("last_sleep",current_time);
		me->set_temp("block_msg/all",1);
		obj->set_temp("block_msg/all",1);
		message_vision("$HIY $N��$n���뱻�У�§��һ��˯���ˣ�����\n\n\n",me,obj);
		
		me->disable_player("˯����");
		obj->disable_player("˯����");

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

		//sleep��,�����Խ�
		me->apply_condition("wc_poison", 0);
		
		if(EQUALSTR(me->querystr("gender"), "����"))
		{
			message_vision("$HIY$N���˹������ƺ����������Ҹ�֮�С�",me);
			me->set_temp("block_msg/all", 0l);
			tell_object(me, "�����˹������ƺ����������Ҹ�֮�С�");
			return;
		}
			
		
		// we add bearing function here. wuliao@xyj Feb. 1997	
		message_vision("$HIY$N���˹��������ϻ��������۵�Ц�ݡ�", me);
		me->set_temp("block_msg/all", 0l);
		tell_object(me, "�����˹��������ϻ��������۵�Ц�ݡ�");
		
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
			message_vision("$HIY\n$N��������һ�����������������ƽ��������\n",me);
			return;
		}
		
		//���������з����
		CContainer * where = me->environment();
		
		if( DIFFERSTR(where->querystr("owner"), who->querystr("id")))
		{
			message_vision("$HIY\n$N��������һ�����������������ƽ��������\n",me);
			return;
		}

		me->set_temp("is_bearing",1);
		me->start_busy(100);
		who->start_busy(100);
				
		message_vision("$HIY\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n", me, who);
		me->call_out(birth1, 15, param1);			
	}

	static void birth1(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = (CChar *)(me->environment())->Present(param1);

		if(! who) return;

		message_vision("$HIY\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n\nӤ���Ѿ�̽����ͷ������\n", me, who);
		me->call_out(birth2, 15, param1);		
	}

	static void birth2(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = (CChar *)(me->environment())->Present(param1);

		if(! who) return;

		message_vision("$HIY \n���ۡ���������Ӥ�������ˣ�\n\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n", me);
		me->start_busy(1);
		who->start_busy(1);
		me->set("hp",0l);
		
		CNpc * baby = load_npc("monster_baby");

		char msg[255];

		baby->set("long", snprintf(msg, 255, "%s����%s��%s�ĺ��ӡ�", baby->Long(), me->name(1), who->name(1)));
		
		if (random(100) < 50)
		{
			baby->set("gender","����");
			baby->set_name( snprintf(msg, 255, "С%s", who->name(1)));
			baby->set("icon", CChar::boy1);
		}	
		else
		{	
			baby->set("gender","Ů��");
			baby->set_name( snprintf(msg, 255, "С%s", me->name(1)));
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
		
		//��¼������
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
		//��ֹ������Ϊno_exercise�ĳ���ʹ��Exercise���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_exercise")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ������");

		int hp_cost, busy_time;
   
		if( (me->environment())->query("no_fight") )
		    return notify_fail("��ȫ���ڽ�ֹ������");
         
        if (me->is_busy() || me->query_temp("pending/exercising"))
            return notify_fail("��������æ���ء�");

		if( me->is_fighting())
			return notify_fail("ս���в������ڹ������߻���ħ��");

		if( ! strlen(me->query_skill_mapped("force")) )
			return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���");

		hp_cost = me->query("env/exercise");
		if( ! hp_cost) 
			return notify_fail("��Ҫ����������������set exercise 10���á�");
		if( hp_cost < 10 ) return notify_fail("������Ҫ�� 10 �㡸����������������set exercise 10���á�");

		if( me->query("hp") < hp_cost )
			return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������");

		tell_object(me, "�������������ù���һ����Ϣ��ʼ������������", "exercise");

		busy_time = hp_cost/20;
		me->start_busy(busy_time + 1);
		me->set_temp("pending/exercising", 1);
   		me->set_temp("exercise_cost", hp_cost);
		
		message_channel("exercise", "$N��ϥ���£���ʼ����������", me);
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
			message_channel("exercise", "$Nһ������û��������ֹ�˴�����", me);

			//��ֹ��������
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
		message_channel("exercise", "$N�˹���ϣ��������˿�����վ��������", me);
		if (me->query("mp") >= me->query("max_mp") * 2)
		{
			if (me->query("max_mp") > me->query_skill("force") * 10) 
			{
				tell_object(me, "���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����", "exercise");
				me->set("mp", me->query("max_mp"));
			}
			else 
			{
				me->add("max_mp", 1);
				me->set("mp", me->query("max_mp"));
				tell_object(me, "������������ˣ���", "exercise");
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

		//��ʾ��ֹԭ����Ϣ
		if(strcmp(how, "halt") == 0)
			message_vision("$N���������е�����ǿ��ѹ�ص��վ��������", me);
		else if(strcmp(how, "kill") == 0)
			message_vision("�ܵ�$n������$Nǿ��ѹ��һ��������վ��������", me, who);
		else
			message_vision("$Nһ������û��������ֹ�˴�����", me);

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
			if (!me) return notify_fail("û������ˡ�");
		}

		if(! strlen(arg) || strcmp(arg, "check") == 0) 
		{
			m = me->query_skill_map();
			if(!m->GetCount())
				return notify_fail("������û��ʹ���κ����⼼�ܡ�");

			tell_object(me, "��������Ŀǰʹ���е����⼼�ܡ�");
			for(int i = 0; i < 22; i++)
			{
				if( ! me->query_skill(valid_types[i]) ) continue;

				const char * ptr = m->querystr(valid_types[i]);
				tell_object(me, snprintf(msg, 255, "%s��%s  ��Ч�ȼ���%d", 
					valid_types[i],
					ptr[0] ? ptr : "��",
					me->query_skill(valid_types[i])) );
			}
			return 1;
		}

		char ski[80], map_to[40];
		char base_skill[10];
		strncpy(ski, arg, 80);
		analyse_string(ski, map_to, 40);
		
		if(! strlen(map_to))
			return notify_fail("ָ���ʽ��enable [<��������> <��������>|none]");

		base_skill[0] = 0;

		for(int i=0; i<22; i++)
			if( strcmp(valid_types[i], ski) == 0 )
				strncpy(base_skill, valid_types[i], 10);

		if(! base_skill[0])
			return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ");

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
			tell_object(me, snprintf(msg, 255, "��%s���ǻ���������Ҫ enable��", base_skill));
			return 1;
		}

		if( !me->query_skill(map_to, 1) )
			return notify_fail("�㲻�����ּ��ܡ�");

		//   if( !me->query_skill(ski, 1) )
			//     return notify_fail("������" + to_chinese(ski) + "����ûѧ�ᣬ������"
			//        + to_chinese(map_to) + "�ˡ�\n");

		if( ! load_skill(map_to)->valid_enable(base_skill) )
			return notify_fail("������ܲ��ܵ���������;��");

		me->map_skill(base_skill, map_to);
		me->delete_temp("perf_quick");
		//me->reset_action();
		tell_object(me, "Ok.");
   
	    if( strcmp(base_skill, "force" ) == 0)
		{
			tell_object(me, "�������һ���ڹ���������������������");
			me->set("mp", 0l);
			me->set("mp_factor", 0l);
			me->receive_damage("hp", 0l);
			me->FlushMyInfo();
		} 

		//�ж��Ƿ�������� lanwood 2001-02-26
		if( strlen(me->query_skill_prepared(base_skill)) )
		{
			CMapping * prepare = me->query_skill_prepare();
			prepare->clear();
			tell_object(me, "�������һ�ֿ��ּ��ܣ����ּ��ܱ������¼�����");
		}

		me->FlushMySkill(me);
		return 1;
	}

	//ȭ����� ��˫�ֻ�������������Ͽ��ּ��ܡ�
	DEFINECMD(Prepare)
	{
		CMapping * smap = me->query_skill_map();
		char basic1[10], basic2[10];
		char valid_types[7][10] = {"unarmed", "finger", "hand", "cuff", "claw", "strike", "leg"};
		
		if( ! smap->GetCount() )
			return notify_fail("������û��ʹ���κ���Ч���⼼�ܡ�");

		CMapping * pmap = me->query_skill_prepare();
		
		if( strcmp(arg, "none") == 0 ) 
		{
			if(! pmap->GetCount() )
				return notify_fail("������û������κ�����ȭ�����ܡ�");

			pmap->clear();

			tell_object(me, "ȡ��ȫ������׼����");
			me->FlushMySkill(me);
			return 1;
		}

		if ( pmap->GetCount() >= 2 ) 
			return notify_fail("�������Ѿ�������������⼼�ܡ�");

		char map_to[40];
		analyse_string(arg, map_to, 40);
		
		basic1[0] = 0; basic2[0] = 0;

		if(map_to[0])
		{
			if ( pmap->GetCount() == 1 ) 
					return notify_fail("����׼����һ�ּ����ˡ�");

			if( !me->query_skill(arg, 1) || !me->query_skill(map_to, 1) )
					return notify_fail("�����ٲ��������ּ�������֮һ��");

			if( ! load_skill(arg)->valid_combine(map_to) 
				&& random(me->query_skill("hubo", 1)) < 50 )
					return notify_fail("������ȭ�����ܲ�����ϡ�");

			for(int i = 0; i < 7; i++)
			{
				if( smap->querystr(valid_types[i]) == arg ) strncpy(basic1, valid_types[i], 10);
				if( smap->querystr(valid_types[i]) == map_to ) strncpy(basic2, valid_types[i], 10);
			}

			if ( !basic1[0] || !basic2[0] ) 
					return notify_fail("������ȭ����δ������Ŀǰ����׼����");

			me->prepare_skill(basic1, arg);
			me->prepare_skill(basic2, map_to);

			me->FlushMySkill(me);
			tell_object(me, "��ɼ���׼����");
			return 1;
		}
			
		if(pmap->GetCount() <= 1 ) 
		{
			if( !me->query_skill(arg, 1) )
				return notify_fail("�㲻�����ּ��ܡ�");

			CVector v;

			pmap->values(v);
			if( pmap->GetCount() == 1 
				&& ! load_skill(arg)->valid_combine(v[0])
				&& random(me->query_skill("hubo", 1)) < 50 )
				return notify_fail("���ּ��ܲ���������м�����ϡ�");

			for (int i=0; i< 7; i++) 
			{
				if( EQUALSTR(smap->querystr(valid_types[i]), arg) ) strncpy(basic1, valid_types[i], 10);
			}

			if ( !basic1[0] ) 
				return notify_fail("���ּ�����δ������Ŀǰ����׼����");

			me->prepare_skill(basic1, arg);

			me->FlushMySkill(me);
			tell_object(me, "��ɼ���׼����");
	
			return 1;
		}
		return 1;
	}

	DEFINECMD(Study)
	{
		//��ֹ������Ϊno_study�ĳ���ʹ��Study���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_study")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ������");
		
		CContainer * where;
		CContainer * ob;
		CMapping * skill;
		CSkill * sk;
		int my_skill;
		char msg[255];
		const char * skill_name;

		where = me->environment();
		if(where->query("no_fight") || where->query("no_magic") )
			return notify_fail("��ȫ���ڽ�ֹ������");
                        
		if( me->is_fighting() )
			return notify_fail("���޷���ս����ר�������ж���֪��");

        if (me->is_busy() || me->query_temp("pending/exercising"))
            return notify_fail("��������æ���ء�");

		if(! (ob = GetSelfObject(me, target)) )
			return notify_fail("��Ҫ��ʲô��");


		if( ! (skill = ob->querymap("skill")) )
			return notify_fail("���޷�����������ѧ���κζ�����");

		if( ! me->query_skill("literate", 1) )
			return notify_fail("���Ǹ���ä����ѧѧ����ʶ��(literate)�ɡ�");

		tell_room(me->environment(), snprintf(msg, 255, "%s��ר�ĵ��ж�%s��", me->name(), ob->name()), me, "study");
		skill_name = skill->querystr("name");
        my_skill = me->query_skill(skill_name, 1);

		sk = load_skill(skill_name);
		
		if( me->query_combat_exp() < skill->query("exp_required") ) 
		{
			return notify_fail("��ĵȼ�����������ô��Ҳû�á�");			
		}

        if ( skill->query("difficulty") - me->query_int() > 0 
			|| my_skill < skill->query("min_skill") )
             return notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�");
	
		if( ! sk->valid_learn(me) ) return 0;

		//�������Ǽ����ж� lanwood 2001-05-27
		if(! me->can_learn(skill_name)) return notify_fail("�����������������ϰ��");

		int cost = skill->query("jing_cost");
		
		cost = cost + cost * (skill->query("difficulty") - me->query_int()) / 20;

		if (cost < 5 ) cost =5;	//minimum cost

		if( my_skill > skill->query("max_skill") ) 
		{
			return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����");			
		}

		int succ = 0;

		if( me->query("hp") > cost ) 
		{
			if( strcmp(sk->type(), "martial") == 0
				&&	my_skill > CChar::level2skill(me->query("level")) ) 
			{
				notify_fail("��ĵȼ�̫�ͣ���%s������˵�Ķ��������޷���ᡣ", ob->name());
			} 
			else 
			{
				tell_object(me, snprintf(msg, 255, "���ж��й�%s�ļ��ɣ��ƺ��е��ĵá�", sk->name(1)), "study");
                me->improve_skill(skill_name, random(me->query_skill("literate", 1) / 2 + 1) + 1);
				succ = 1;
			}
		} 
		else 
		{
			cost = me->query("hp");
			notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��");
		}

		me->receive_damage("hp", cost );
		return succ;
	}

	DEFINECMD(Practice)
	{
		//��ֹ������Ϊno_practice�ĳ���ʹ��Practice���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_practice")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ������");

		char msg[255];

		if(( (me->environment())->query("no_fight") &&!(me->environment())->query("no_��")) || 
			(me->environment())->query("no_magic") )
			return notify_fail("��ȫ���ڽ�ֹ������");

		if (me->is_busy())
                return notify_fail("��������æ���ء�");

		if( me->is_fighting() )
			return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�");

		if(! strlen(arg))
			return Enable(me, 0, arg);

		const char * skillname = me->query_skill_mapped(arg);
		if( ! skillname[0] )
			return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�");

		int skill_basic = me->query_skill(arg, 1);
		int skill = me->query_skill(skillname, 1);

		if( skill < 1 )
			return notify_fail("�����û��ѧ�᡹����ܰɣ������ȥ��̱��ˡ�");
		
		if( skill_basic < 1 )
			return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��");

		if( skill  >= CChar::level2skill(me->query("level")) )
			return notify_fail("��ĵȼ������������ٶ�Ҳû�á�");

		notify_fail("�����ڲ�����ϰ����ܡ�");

		CSkill * sk = load_skill(skillname);
		if( ! sk->valid_learn(me) ) return 0;

		//�������Ǽ����ж� lanwood 2001-05-27
		if(! me->can_learn(skillname)) return notify_fail("�����������������ϰ��");

		notify_fail("��������ϰ%s���ǲ�û���κν�����", sk->name(1));

        if(skill_basic <= skill && random(100)==0)
			tell_object(me, snprintf(msg, 255, "���%s��������ˣ���������ʦ�������̰ɣ�", sk->name(1)));

		if( sk->practice_skill(me) ) 
		{
			me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
			tell_object(me, snprintf(msg, 255, "$CYN���%s�����ˣ�",   sk->name(1)), "practice");
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
		//����������Ϣ	1.7�汾 lanwood 2001-03-23
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
			return notify_fail("����������ڼ��ֹʹ�ã�");
				
		if(( env->query("no_fight") || env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹս����");

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ��˭�д裿");
		
		if(env->Query(CChar::IS_FIGHTROOM)) return 1;		//�Ѿ���ս���ˡ�

		if( !living(who) )
			return notify_fail("%s�Ѿ��޷�ս���ˡ�", who->name()); 

		if(who == me)	
			return notify_fail("�㲻�ܹ����Լ���");

		if(who->is_busy())
			return notify_fail("�Է�û�����㡣");

		if(me->querymap_temp("biwu"))
		{
			CContainer * env1 = load_room("���괺����¥");
			if(!env1->query("biwu"))
				me->delete_temp("biwu");
		}

		if( userp(who) && who->query_temp("pending/fight")!=me->object_id() ) 
		{
			message_vision(snprintf(msg, 255, "$N����$n˵����%s%s�����%s�ĸ��У�",
				query_self(me), me->name(), query_respect(who)),
				me, who);

			me->set_temp("pending/fight", who->object_id());
			return 1;
		}

		if( who->query("can_speak") ) 
		{
			message_vision(snprintf(msg, 255, "$N����$n˵����%s%s�����%s�ĸ��У�",
				query_self(me), me->name(), query_respect(who)),
				me, who);

			notify_fail("������%s��������������", who->name());
			if( who->Query(CChar::IS_NPC) && ! ((CNpc *)who)->accept_fight(me) ) return 0;

			snprintf(msg, 255, "%s��%s�ı���", me->name(), who->name());
			Do_BiShi(me, who, msg, 50);
		} 
		else 
		{
			message_vision("$N���һ������ʼ��$n����������", me, who);
			who->kill_ob(me);
		}

		return 1;
	}

	DEFINECMD(Follow)
	{
		//��ֹ������Ϊno_follow�ĳ���ʹ��Follow���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_follow")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ�������ˡ�");

		CChar * who;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ����˭��");

		if(who == me)
		{
			me->set_leader(0);
			tell_object(me, "ȡ�����棡");
			return 1;
		}

		me->set_leader(who);
		message_vision("$YEL$N������ʼ����$nһ���ж���", me, who);
		return 1;
	}

	DEFINECMD(Say)
	{
		CChar * who;
		char msg[512], names[40];

		if (!strlen(arg)) 
		{
			message_vision("$HIC$N�������ﲻ֪����˵Щʲô��", me);
			return 1;
		}

		if(!g_Channel.check_channel_msg(me, "say", arg, 0))
			return 0;
		
		//��ֹ������Ϊno_say�ĳ���ʹ��Say���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_say")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ˵����");

		if(me->query("no_say")||me->query_temp("no_say"))
			return notify_fail("���ڷ����˴�����Ϣ�����˵��Ȩ������ֹ�ˡ�");

		who = GetRoomChar(me, target);
		if(!who || who == me)
			strcpy(names, "$HIC$N˵����");
		else
			strcpy(names, "$HIC$N��$n˵����");
		
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

			//who��say������Ӧ
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
				if(env->query("room_locked") & FIGHT_NO_FLEE)	//������
					return notify_fail("��ս������ס���޷����ѡ�");					
				

				if(env->is_bishi())
				{
					message_vision("$N�������һԾ������սȦ�����ˡ�", me); 
					env->End_Fight();
				}
				else 
				{
					//busy�в�������
					if(me->is_busy()) return notify_fail("��û�����ܣ�");

					if(! CheckAP(50, me)) return 0;
					if(env->Do_Flee(me))
						ResumeAP(50, me);
				}
				//if(me->query_temp("biwu")) 
				//shout(WHT"���������š�"+me->name()+"��;�������䣡\n" NOR);
			}
			else	//��ս
			{
				me->move(env->environment());
				tell_room(env, snprintf(msg, 255, "%sֹͣ��ս��", me->name()));			
				message_vision(snprintf(msg, 255, "$N�뿪��%s��", env->name()), me);
			}

			return 1;
		}
		else if (!me->is_busy()) 
			return notify_fail("�����ڲ�æ��");
		
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
				return notify_fail("��Ҫ�۲�ʲô��");
		}
		else
			who = me->environment();

		if(! who->do_look(me))
			who->SendMenu(me);

		return 1;
	}

	DEFINECMD(MakeLove)		//�����ŵ�ָ���ɫ��ɷ֡��Ǻǡ�
	{
		CChar * who;

		//���ſ���
		if(! g_Combatd.query("makelove")) return 0;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("�����˭������\n");

        if( EQUALSTR(me->querystr("gender"), who->querystr("gender")) )
            return notify_fail("����...�������²��аɣ�");

        if(!living(who))
            return notify_fail("�˼Ҷ������ˣ��㻹...");

		if( me->is_busy() )
			return notify_fail("( ����һ��������û����ɡ�)");
	
        if( EQUALSTR(me->querystr("gender"), "����") )
            return notify_fail("��һ��̫�࣬Ҳ������°������ǲ��Ǹ�Ц��");

		CContainer * env = me->environment();
		if( ! env || ! env->query("sleep_room"))
            return notify_fail("�ܵ��Ҹ���ܰ����ĵط��ɡ�");

		//����Ƿ����Թ���
		DTItemList * list = env->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		while(p)
		{
			CContainer * obj = list->GetNext(p);
			if( obj->is_character() && obj !=me
                  && obj != who && ! wizardp((CChar *)obj) )
                      return notify_fail("������б����أ��಻����˼ѽ��");
		}

		char msg[255];

        if(!me->query_temp("makelove/quest")) 
		{
            if( EQUALSTR(me->querystr("gender"), "����") ) 
			{
                 message_vision("$YEL$N�����ע����$n��˫��§��$n��С������\n���������$n��С����....\n", me, who);
                 tell_object(who, snprintf(msg, 255, "$HIR������������㹲��������\n�����Ը�⣬����Ҳ��%s��һ�� makelove ָ�\n", me->name()) );
            }
            else 
			{
                 message_vision("$YEL$N��С���������˵ģ���������ס$n�Ĳ��ӣ���ǰ����������$n��\n���ţ�С���ཱུĴ��������������$n���촽....\n", me, who);
                 tell_object(who, snprintf(msg, 255, "$HIRɵ��Ҳ�ܿ�����������㹲��������\n�����Ը�⣬����Ҳ��%s��һ�� makelove ָ�\n", me->name()) );
            }
            
			who->set_temp("makelove/quest",1);
        }
        else 
		{
             if( EQUALSTR(me->querystr("gender"), "����") ) 
			 {
                  message_vision("$YEL$N���˺ð��죬ʵ���ܲ���$n������\nͻȻһ�ѽ�$n������סѹ�ڴ���....\n", me, who);
                  me->call_out(over, 1, target);
             }
             else 
			 {
                  message_vision("$YEL$N������������$n���ȵ���������ͷС¹ײ����ͣ��\n����̱����$n�Ļ����$nһ�Ѻᱧ������������ķ��ڴ���....\n", me, who);
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

        message_vision("$HIB...�����$HIR����$HIB��������...\n", me);
        if(me->query("hp") < 30 || who->query("hp") < 30 )
        {
            if(me->query("hp") < 30 ) 
			{
                 message_vision("$HIR$NͻȻ������Ѫ���ε��ڵء����������������ˡ�\n", me);
                 me->unconcious();
                 me->add("makeloved",1);
                 who->add("makeloved",1);
             }
             else 
			 {
                 message_vision("$HIR$NͻȻ������Ѫ���ε��ڵء����������������ˡ�\n", who);
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
				        message_vision("$HIR$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n", me);
                        me->unconcious();
                        who->add("hp", who->query_str() - 55 + random(10));
                        who->add("makeloved",1);
                        me->add("makeloved",1);
                        break;
                case 1:
                        message_vision("$HIR$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n", who);
                        who->unconcious();
                        me->add("hp", who->query_str() - 55 + random(10));
                        who->add("makeloved",1);
                        me->add("makeloved",1);
                        break;
                default:
                        if(random(10) > 7) 
						{
                                message_vision("$YEL$N����һ����ͷ�������һ������΢΢������$n��\n��˵����Ҫ��Ȼ...��������һ��...\n", me, who);
								who->add("makeloved",1);
								me->add("makeloved",1);
                        }
                        else 
						{
                                message_vision("$HIM$n�����۾����������ڴ��ϣ��е��Լ����ϵ��·�\nһ��һ���ı��ѵ���ͻȻ$n�е�$N���̵�����ѹ�����Լ�...\n", me, who);
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

         message_vision("$HIR$N���������$n�Ĵ������ƿ�ʼ�����ֵĸ���$n��\n������Ӱ�ļ�����$n����������˫�������ı�ס$N...\n", ob, who);
		 me->call_out(over2, 3, param1);

		 me->start_busy(3);
		 who->start_busy(3);
	}

	static void over2(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

         message_vision("$WHT$NҲԽ��Խ�˷ܣ����ں�$n��Ϊһ�壬ֻ��$n\n�����Ӱ�ġ�����������һ��������ʹ�࣬�������...\n", ob, who);
         me->call_out(over3, 3, param1);

		 me->start_busy(3);
		 who->start_busy(3);
	}

	static void over3(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

         message_vision("$HIW$N�Ķ���Խ��Խ�죬Խ��Խ�ͣ�$n�������$N�Ľ���\n�ͷų���$N�İ�����������,�������ڣ���������...\n", ob, who);
         me->call_out(over4, 3, param1);

		 me->start_busy(3);
		 who->start_busy(3);
	}

	static void over4(CContainer * ob, LONG param1, LONG param2)
	{
		CChar * me = (CChar *)ob;
		CChar * who = GetRoomChar(me, param1);

		if(! who) return;

        message_vision("$HIM��ӿ���ȵĸ߳�����$n��˳������$N�Ļ������\n$N����������$N����ĸ�Ū��$n�⻬��Ƥ������������...\n", ob, who);
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


