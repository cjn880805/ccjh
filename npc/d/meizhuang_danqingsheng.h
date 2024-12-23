// meizhuang_danqingsheng.c 
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNmeizhuang_danqingsheng);

virtual void create()
{
	set_name("��Ѫ����", "danqing sheng");
	set("title", "÷ׯ��ׯ��");
	set("long","������÷ׯ��λׯ�����е��ĵĺ���������һ���ɸɾ�������ɫ���ۡ�����������Ѯ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�");
	set("gender", "����");
	set("age", 40);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
 	set("icon",old_man2);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	set("combat_exp", 300000);
	set("repute", 15000);
	set("score", 60000);
	set("item_count", 1);
	
	set_skill("force", 100);
	set_skill("wuzheng_xinfa", 120);
	set_skill("dodge", 100);
	set_skill("piaoyibu", 110);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("wuyun_jianfa", 100);
	set_skill("literate", 130);
	
	map_skill("force", "wuzheng_xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun_jianfa");
	map_skill("sword", "wuyun_jianfa");
	
	create_family("÷ׯ", 1, "ׯ��");

	set_inquiry("��������","���������ĳ���£�ǧ�����أ�һͰ������");
	set_inquiry("������","������");
	set_inquiry("÷����","÷��������÷ׯ���");
//	set_inquiry("����",ask_me);
	carry_object("changjian")->wield();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query("repute") < 0) 
	{
		say("��÷ׯ��Ȼ����ʲô��������, ����ͽҲ��Ϊ�ϸ�", ob);
		say(snprintf(msg,255,"��Ʒ�з��棬%s�Ƿ����ò�����",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query_skill("wuzheng_xinfa",1) < 30) 
	{
		say("���ǲ�������ͽ�ġ�", ob);
		say(snprintf(msg,255,"����÷ׯ���ڹ��ϣ�%s�Ƿ�Ӧ�ö��µ㹦��",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	say("�ðɣ����¾��������ˡ�");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}


virtual int prevent_learn(CChar * me, const char * arg)
{
	if (me->query_temp("teapot/plum") == 1 )
        message_vision("��Ѫ���࿴�˿�$N��˵�������Ѿ�ʵ���˵����ŵ�ԣ����ڲ����ٽ���ʲô�ˡ�", me);

    me->add_temp("teapot/plum", -1);
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
    
    if (! me->query_temp("teapot/plum"))
        return 0;

    return 1;
}

virtual int accept_object(CChar * me , CContainer * item)
{
	
	if ( EQUALSTR(item->querystr("base_name"), "meihualing" ))
	{
		if (!me->query_temp("teapot/plum")) 
			me->set_temp("teapot/plum",4);
		
		message_vision("��Ѫ���࿴�˿�$N��÷���˵����������ˣ���ɴ�������ѧ�㶫����", me);;
		me->add_temp("teapot/plum", 4);
		destruct(item);
		return 1;
	}

	if (item->query("ry/menpiao") &&  EQUALSTR(item->querystr("owner1"), me->id(1)))
	{
		if (me->query_temp("ry/renwu1_1")) 
		{
			char msg[255];
			say(snprintf(msg,255,"��Ѫ���࿴�˿���ݹ����ġ�%s����˵�����ף����������Ŀ��͸�����һ����ʲô��ͼ�������ʵ˵�ɣ���",item->querystr("name")), me);
			me->set_temp("ry/renwu1_2",4);//�͸���ׯ����Ʊ
			SendMenu(me);
			destruct(item);
			return 1;
		}
	}
	return 0;
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu1_2") ==4)
	{
		if(! strlen(ask))
		{
			AddMenuItem("ѯ�ʹ���ǰ��������Ѻ����","jiaozhu",me);
			AddMenuItem("���ǰ��͵ģ�ϣ����ϲ��","song",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "jiaozhu") )
		{
			tell_object(me,"\n$HIR��Ѫ������ɫ��ʱ�����������ߵ�����������ʱ�������ľ�֪��û�����ģ���Ȼ���������������Ǹ��ϼһ�ģ��ϻ���˵�����аɣ���\n");
			((CUser *)this)->Ready_PK();
			((CUser *)me)->Ready_PK();
			me->kill_ob(this);	
			this->kill_ob(me);
			set("owner",me->object_id());
		}
		else if(!strcmp(ask, "song") )
		{
			say("��Ѫ����Ц˵��������������",me);
			tell_object(me,"\n$HIC���������Ʊ�����񣬵õ���Ǯ50Ԫ�Ľ�����\n");
			me->delete_temp("ry");
			me->delete_temp("no_fei");
			CMoney::Pay_Player(me, 50);
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	if(query("owner"))
	{
		CChar * killer;
		CChar * owner;
		if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
		{
			//���owner
			owner = (CChar *)find_object(query_temp("fight/owner"), 1);
			if(owner && owner->query_temp("fight/will_nk") == object_id())
				killer = owner;
			
			CContainer * obj = load_item("baozi");
			obj->set_name("ˮ��ʯ��Կ��","yao si");
			obj->set("long","����һöԿ�ס�");
			obj->set("owner1",killer->id(1));
			obj->set("ry/yaosi",1);
			obj->move(environment());
		}
	}
	CNpc::die();
}

/*static char * ask_me(CNpc *who,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (!(me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "÷ׯ"))
		//return query_respect(me) +"�뱾��������������֪�˻��Ӻ�̸��";
		return  snprintf(msg,255,"%s�뱾��������������֪�˻��Ӻ�̸��",query_respect(me) );

	if (who->query("item_count") < 1)
		return "�������ˣ�÷�����Ʋ��ڴ˴���";
	who->add("item_count", -1);
	obj = load_item("meihualing");//÷���� lanwood 2000-12-28
	obj->move(me);
	return "�ðɣ����÷�����ƾͽ����㱣���ˡ�";
}*/ 

NPC_END;