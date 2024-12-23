//jian.h
//Lanwood 2000-01-06

NPC_BEGIN(CNgaibang_jian);

virtual void create()
{
	set_name("������", "jian youzhao");
	set("title", "ؤ��Ŵ�����");
	set("nickname", "ִ������");
	set("gender", "����");
	set("age", 50);
	set("long", 
		"��������ؤ���ִ�����ϣ�������ִ�Ʒ����Լ�������ȡ�");
		
	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);
	set("icon",begger);

	set("hp", 900);
	set("max_hp", 1800);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	set("combat_exp", 150000);
	set("score", 20000);
	
	set_skill("force", 95); 			// �����ڹ�
	set_skill("huntian_qigong", 90); 	// ��������
	set_skill("unarmed", 100); 			// ����ȭ��
	set_skill("xianglong_zhang", 95); 	// ����ʮ����
	set_skill("dodge", 90); 			// ��������
	set_skill("xiaoyaoyou", 90); 		// ��ң��
	set_skill("parry", 85); 			// �����м�
	set_skill("staff", 90); 			// ��������
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 18, "�Ŵ�����");

	set_inquiry("������", ask_qingzhu_ling);
	set_inquiry("������", ask_qingzhu_zang);
	set("chat_chance_combat", 20);
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	say("�Ϸ���ͽ�ܣ�������ذɡ�", me);	
	SendMenu(me);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
        
    if(userp(me) && !is_fighting()) 
	{
		if( EQUALSTR( (me->environment())->querystr("base_name"), "��������10") && DIFFERSTR(me->querystr("family/family_name"), "ؤ��"))
		{
			remove_call_out(do_saying);
			call_out(do_saying, 1, me->object_id());
        }
	}
}

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CContainer * env = ob->environment();
	CChar * who = (CChar *)env->Present(param1);

    if (! who) return;
	if(DIFFERSTR(env->querystr("base_name"), "��������10"))
		return;

	message_vision("���Ͽ���$Nһ�ۣ������˵����������������˼�˵�Ҳ����������ؤ����ӣ�\n���ֲ�����ؤ��Ҵ����ܿ��԰ɣ���\n˵������һ̧��$N˳��Ӧ��һ������ɵġ�ƨ�����ƽɳ����ʽ��������ߴ", who);
	
	who->move(load_room("��������9"));
	tell_room(who->environment(), 
		snprintf(msg, 255, "ֻ�����ء���һ����������%s��С������˳�����ƨ������һ�������Ьӡ", who->name()), who);
}

//edit by wolfman
//2001-7-24
static char * ask_qingzhu_zang(CNpc * me, CChar * who)
{
	if (DIFFERSTR(me->querystr("family/family_name"), "ؤ��"))
		return "���ֲ��Ǳ�����ӣ���ΪʲôҪ�����������ȣ�";

	if (who->PresentName("qingzuzang",IS_ITEM))
		return "���Ѿ����������ˣ������˲�Ҫ̫̰�ġ���";

	me->say("������������������������������ģ�����������ӣ��һ������һ�������ȡ�",who);
	if (!who->PresentName("qingzugang",IS_ITEM))
	{
		return "���������ӵ�ʱ���������Ұɡ�";
	}
	me->say("�ã��ã���Ȼ���������ӣ��ҾͰ�����һ���ɡ���",who);
	destruct(who->PresentName("qingzugang",IS_ITEM));
	load_item("qingzuzang")->move(who);
//	message_vision("$N�Ӽ������нӹ�һ�������ȡ�",who);
	me->say("���ϴ������нӹ����ӣ�ת����ȥ����",who);
	return "Ƭ�̣����ϵݸ���һ�������ȣ�������������Ҫ��ɱ�޹���";
}

static char * ask_qingzhu_ling(CNpc * me, CChar * who)
{
	if(EQUALSTR(who->querystr("family/family_name"), "ؤ��"))
	{
		if (who->PresentName("qingzhu_ling", IS_ITEM))
			return "�����ϲ��Ǵ��ű��������𣿣�";
		load_item("qingzhu_ling")->move(who);
		return "�ú��ˣ�������Ϊ�ɡ�";
	}
	return "�����뱾���ز���ʶ��ƾʲôǰ����Ҫ�������";
}

int accept_object(CChar * me, CContainer * obj)
{
	char msg[255];

	if( EQUALSTR(obj->querystr("base_name"), "po_bu")
		&& me->query_temp("have_cloth"))
	{
		me->set("party/party_name","ؤ��");
		me->set("party/rank", me->querystr("newtitle"));
		me->del("newtitle");

		int level = me->query("beggarlvl");
		if(level == 0)
			me->set("beggarlvl", 1);
		else
		{
			level ++;
			me->set("beggarlvl", level);
		}
		message_vision(snprintf(msg, 255, "$N����$n˵���ã���ϲ������%s�������Ŭ���ض�ǰ;�޿�������",  me->querystr("party/rank")), this, me);
		return 1;
	}
	else
	{
		say("�㵱�ҽл��Ӱ���ʲô���������������ң��ߣ�");
		return 0;
	}
}

NPC_END;
