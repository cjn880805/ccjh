//yong_rong Ӻ�� 
//����������BOSS
BOSS_BEGIN(CNyong_rong);

virtual void create()
{
	set_name("Ӻ��", "yong rong");
	set("title", "ɱ����ҽ");
	set("gender", "Ů��");
	set("icon", young_man3);
	set("nickname", "����֮��");
	set("long",  "�����ü�������������˫�۾����ĵ�ֱ���Թ��˻��ǡ�����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��������ȻһЦ�����������·����۲���ת֮�䣬���һ����������飬�������м����ľ��硣");
	set("age", 21);
	
	set("str", 85);
	set("int", 85);
	set("con", 85);
	set("dex", 85);
	set("per",31);
	set("level",180);

	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set_inquiry("�ĺ�����", "���ڽ��������������");
	set_inquiry("��ϼ��", "��ɽ��õ������ڹ�֮һ����һֱ���������˲Ź���������,�㲻֪����");
	set_inquiry("�Ž�", "����Ž������ĳϡ�");

	set("hp", 82000);
	set("max_hp", 82000);
	set("mp", 47000);
	set("max_mp", 47000);
	set("mp_factor", 500);
	
	set("combat_exp", 140000000);
	set("score", 500000);
	
	set_skill("unarmed", 660);
	set_skill("sword", 660);
	set_skill("force", 660);
	set_skill("parry", 660);
	set_skill("dodge", 660);
	set_skill("literate", 660);
	set_skill("huashan_shenfa", 660);
	set_skill("huashan_sword", 660);
	set_skill("zixia_shengong", 660);
	set_skill("hunyuan_zhang", 660);
	
	map_skill("sword", "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "huashan_shenfa");
	   	
	set("no_kill",1);
	set("no_���־�",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_�������",1);
	set_temp("apply/no_ƴ��",1);
	set_temp("apply/no_��Ѫ��",1);
	set_temp("apply/no_���־�",1);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 800);
    set("apply/damage", 670);

	set("chat_chance", 5);
	carry_object("changjian")->wield();

	set("family/family_name","��ɽ��");
	
	call_out(do_full, 7200);
	
}

static void do_full(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->query_temp("fight/is_fighting"))
	{
		message_vision("\n$HIR$N�������£��˹���Ϣ��", me);
		me->set("mp",me->query("max_mp"));
		me->set("hp",me->query("max_hp"));
	}
	me->call_out(do_full, 7200);
}

virtual char * chat_msg()
{
	switch(random(14))
	{
	case 0:
		return "Ӻ�ݺ�Ȼ���˸�������Ц��: �������ȥ������";
	case 1:
		command("sing2");
		break;
	case 2:
		command("angry");
		break;
	case 3:
		command("slogan2");
		break;
	case 4:
		command("yawn");
		break;
	case 5:
		command("lazy");
		break;
	case 6:
		command("laughproud");
		break;
	case 7:
		return "Ӻ�ݺ�Ȼ����˵���򵹳���̶����С�䣡";
	case 8:
		return "Ӻ�����ĵ������־̾��: ����һ���ˣ���û��˼��";
	case 9:
		return "Ӻ�����������һ���С�֣������°�˵: ˭�����˵˵��?";
	case 10:
		return "Ӻ��ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������";
	case 11:
		return "Ӻ�ݺ�Ȼݸ��һЦ��: С��������Ҫ��ɱ˭�أ�";
	case 12:
		return "Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ��������������ˡ�";
	case 13:
		command("reclaim");
		break;
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword jianzhang", 1);
			break;
		case 1:
			perform_action("force powerup", 0);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(4))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("unarmed wuji", 1);
			break;
		case 2:
			perform_action("force powerup", 0);
			break;
		case 3:
			carry_object("changjian")->wield();
			break;
		}
	}
	return 0;
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//���һ���򵹵��˽���ý�����һ����ʸ�
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>130 )
		{
			message_vision("$HIR$N����������$n��Ȼ����һ�ܣ��Ǿ�ȥ��һ������ɣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level6"))
				me->set("18dy/level7",1);
			me->move(load_room("�߲���ʺ����"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
