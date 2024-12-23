// ding.c ������
//code by cat
//2001-02-21

ZUSHI_BEGIN(CNxingxiu_ding);

virtual void create()
{
	set_name("������", "ding");
	set("nickname","�����Ϲ�");
	set("long", "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����ɡ�����������ò���棬�ɷ���ǡ�");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -100);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 21000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_force", 100);
	set("combat_exp", 1500000);
	set("score", 4000000);
	
        set_skill("throwing", 320);
	set_skill("feixing_shu", 300);        
	set_skill("force", 320);
	set_skill("huagong_dafa", 300);
	set_skill("dodge", 300);
	set_skill("zhaixinggong", 310);
	set_skill("strike",300);
	set_skill("xingxiu_duzhang", 320);
	set_skill("parry", 298);
	set_skill("staff", 320);
	set_skill("tianshan_zhang", 325);
	set_skill("literate", 280);
	set_skill("sanyin_wugongzhao", 320);
	set_skill("claw", 320);
	set_skill("poison", 400);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu_duzhang");
	map_skill("parry", "feixing_shu");
	map_skill("staff", "tianshan_zhang");
	map_skill("unarmed", "xingxiu_duzhang");
	map_skill("claw", "sanyin_wugongzhao");
        
	prepare_skill("unarmed", "xingxiu_duzhang");
	prepare_skill("claw", "sanyin_wugongzhao");

	create_family("������", 1, "��ɽ��ʦ");
//	set("class", "taoist");

//	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "������" ))
	{
		if(strcmp(ask, "����") == 0)
		{
			const char * ptr = ask_zhangmen(this, me);
			if(ptr)
			{
				say(ptr, me);
				SendMenu(me);
			}			
			return 1;
		}
        
		AddMenuItem("��������������֮λ", "����", me);
		AddMenuItem("������PP", "$2flatter $1 $2", me);
		SendMenu(me);
		return 1;
	}
	
	return CNpc::do_talk(me, ask);
}  

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "flatter") == 0)
		return do_flatter(arg, me);

	return CNzushi::handle_action(comm, me, arg);
}

int do_flatter(char * arg, CChar * me)
{
	char msg[255];

	if(! strlen(arg))//����Ϊ��
		return notify_fail("��˵������ʲô��");

	if(! me->query_temp("pending/flatter"))//��û���Ҫ��ʦ��
		return notify_fail("����Ҳ�Ǹ���˵�����ˣ�����������ʲô�£�");

	message_vision( snprintf(msg, 255, "$N����˵����%s" , arg), me);
	
	if(strstr(arg, "��������") && (strstr(arg, "�������") || strstr(arg, "�������") || strstr(arg, "�Ž��ޱ�")))
	{
		//˵����
		me->delete_temp("pending/flatter");
		if(me->query_skill("huagong_dafa",1) < 80)//����������80��
			return notify_fail("��Ļ����󷨹������㣬Ҫ�������洫Ϊʱ���磬��ȥ�������ɡ�");
		else//������
		{
			say ("�����������ĺ��������⣬������Ϊͽ�ɡ�");
			command(snprintf(msg,255,"recruit %ld",me->object_id()));		
		}
	}
	else//PP���ڴ�����
		return notify_fail("�㲻���ҷ������������ô������Ϊͽ��");

	return 1;
}
	
virtual void attempt_apprentice(CChar * player)
{
	if (player->query("betrayer"))
	{
		say ("��Խ����Խ�������Ե׵ġ�");
		return;
	}
	
	if( player->query_temp("pending/flatter") ) 
	{
		say ("����˲������ɷ�����������������㣿");
		return;
	}
	else
	{
		say ("���������ɱ������������ʥ����ô������");
		message_vision("��������΢��˫�ۣ������룬һ��������������ӡ�",player);
		player->set_temp("pending/flatter", 1);
	}
}

// �������ɣ�������أ��������Ž��ޱ�

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "���޺����¶�" ))
		return notify_fail("�����������");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
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
		if(me->query_temp("fight/is_fighting") && is_fighting(me)!=is_fighting(this) && me->query_temp("��ɽ�۽�/�Ǽ�"))
		{
			me->set_temp("��ɽ�۽�/����",1);
			break;
		}
	}
	CNpc::die();
}

ZUSHI_END;