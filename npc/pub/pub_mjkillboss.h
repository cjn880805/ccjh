//pub_mjkillboss.h ��ʦ̫
//�ز� 2002��4��25

NPC_BEGIN(CNpub_mjkillboss);

virtual void create()
{
	set_name("��ʦ̫", "miejin shitai");
	set("long", "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�");
	set("gender", "Ů��");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 100000);
	set("class", "bonze");
	set("chat_chance_combat", 30);
	set("icon", taoistess);
	set("foolid",13);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("per", 20);
	set("bigboss",1);
	set("no_chan",1);
	set("no_kill",1);
	
	set("max_hp", 50000+random(10000));
	
	set("mp", 10000);
	set("max_mp", 10000);
	set("kill/level",50);
	
	set("combat_exp", 20000000);
	set("score", 1000);
	set("level", 140);
	set_skill("persuading", 350);
	set_skill("throwing", 350);
	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("finger", 350);
	set_skill("parry", 350);
	set_skill("strike", 350);
	set_skill("sword", 350);
	set_skill("blade", 350);
	set_skill("literate", 350);
	set_skill("mahayana", 350);
	set_skill("buddhism", 350);
	set_skill("jinding_zhang", 450);
	set_skill("tiangang_zhi", 350);
	set_skill("huifeng_jian", 350);
	set_skill("yanxing_dao", 350);
	set_skill("zhutian_bu", 350);
	set_skill("linji_zhuang", 350);

	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("blade","yanxing_dao");
	map_skill("parry","huifeng_jian");

	prepare_skill("strike", "jinding_zhang");
	create_family("������", 3, "������");
	
	carry_object("ytjian")->wield();
	carry_object("cloth")->wear();
	set("chat_chance", 80);
	call_out(do_die, 7200);

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
	
	set("bigboss",1);

};


virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword mie");
		break; 
	case 1:
		if(query("hp") /2 < query("max_hp") / 3)
			perform_action("force recover", 1);
		break;
	case 2:
		if(query("hp") /2 < query("max_hp") / 3)
		{
			int i=random(4);
			if(!i)
				perform_action("force recover", 1);
			else if(i == 1)
				eat_yao("yaopin_1");
			else if(i == 2)
				eat_yao("yaopin_2");
			else
			{
				if(!random(5))
					eat_yao("jiuhua");
				else
					eat_yao("xiaohuan_dan");
			}
		}
		break;
	}
	return 0;
}

void eat_yao(char * yaopin)
{
	char msg[40];
	CContainer * yao = load_item(yaopin);
	yao->move(this);
	command(snprintf(msg, 40, "use %ld", yao->object_id()));
}

virtual int accept_fight(CChar *me)
{
	say("������");
	return do_kill(me);
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "kill") == 0)
		return do_kill(me);
	
	return CNpc::handle_action(comm, me, arg);
}

int do_kill(CChar * me)
{
	((CUser *)this)->Ready_PK();
	this->kill_ob(me);
	me->kill_ob(this);	
	return 1;
}

void bl_move()
{
	char msg[255];
	int i=query("teapot/bl");
	if(i==24)
	{
		set("teapot/bl",0l);
		i=0;
	}
	else
		message_vision(snprintf(msg, 255, "%s��ǰ����ȥ��",this->name()), this);
	
	static char bnline[24][20]={"���̹㳡","���̴��","���̵���Ů��","�������Ź㳡","������ʯ���1","������ʯ���2",
		"����ɽ��","������ʯ���3","����������","�����һ����Ʒ�","������ʯ���7","������ʯ���8","������ʯ���9",
		"���̺��������","������ʯ���9","������ʯ���8","������ʯ���7","�����һ����Ʒ�","�����һ������","������΢��",
		"���̹㳡","���̷���","���̹㳡","���̴��"};

	CRoom * troom;
	troom=load_room(bnline[i]);
	move(troom);
	set("teapot/bl",i+1);
	return ;
}

char * chat_msg()
{
	char msg[255];
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target) || wizardp(target))	continue;
		if(!target->is_fighting() && (EQUALSTR(target->querystr("family/family_name"), "����")||target->query("mj"))
			&& DIFFERSTR(target->querystr("base_name"), "zm_mingjiao"))
		{
			if(query("nokill/count"))
			{
				for(int i=1;i<query("nokill/count");i++)
				{
					if(EQUALSTR(querystr(snprintf(msg, 255,"nokill/%d",i)),target->name(1)))
					{
						set("nokill/id",1);
						break;
					}
				}
			}
			if(query("nokill/id"))
			{
				del("nokill/id");
				continue;
			}
			if(target->query("cailiao"))
				continue;
			message_vision(snprintf(msg, 255, "%s��%sһ����ȣ���ħ���������������������ڡ���",this->name(),target->name()), this);
			if(environment()->query("no_fight"))
			{	
				environment()->set("no_fight", 0l);	//ǿ�ȴ˵ؿ���ս��
			}
			((CUser *)this)->Ready_PK();
			((CUser *)target)->Ready_PK();
			target->kill_ob(this);	
			this->kill_ob(target);	
			break;
		}
	}
	if(!random(3))bl_move();
	return "";
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	char msg[255];
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		if(me->query_temp("fight/is_fighting") && is_fighting(me)!=is_fighting(this) && EQUALSTR(me->querystr("party/party_name"), "����"))
		{
			int exp_mj=1+query("kill/level")*3;
			me->add_temp("mj/exp",exp_mj);
			int exp=random(100*(query("kill/level")+1))+1;
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY������$HIR%ld$HIY���ʵս���顢$HIR%ld$HIY��Ĺ�ѫֵ��", exp,exp_mj));
		}
		else if(!me->query_temp("fight/is_fighting") && EQUALSTR(me->querystr("party/party_name"), "����"))
		{
			me->add_temp("mj/exp",1);
			int exp=random(10)+1;
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY������$HIR%ld$HIY��Ĺ�Ħ���顢$HIR1$HIY���������ѫֵ��", exp));
		}
	}
	g_Channel.do_channel(this, NULL, "chat", 
		"\n\n$HIW��̾һ���������������������Щ���������������Ը����Υ�������������˰��ˣ�ƶ���������������������֮������\n�����þ�ƽ��֮������ָ������ֻ�����콣�����ѣ�������һƬ����֮�У���Ȼ��ȥ��\n\n");
	message_vision("$N���ˡ�", this);
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		env->add(snprintf(msg, 255,"����/%s",this->name(1)),1);
		env->add("����/count",1);
		env->set("����/boss",1);
	}
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	me->move(load_room("pk"));
	CContainer * env = me->environment();
	if(env->query("mj/start"))
	{
		env->add("����/boss",1);
		env->add("����/count",1);
	}
	destruct(me);
}
NPC_END;





