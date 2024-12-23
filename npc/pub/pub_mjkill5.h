//pub_mjkill5.h ��ɽ����
//�ز� 2002��4��25

NPC_BEGIN(CNpub_mjkill5);

virtual void create()
{
	static struct{
		char name[20], id[20];		//��������
		int	 icon;			//ͼ��
		int  chance;		//���ּ���
	}mon[10] = {
		{"��������", "duguliuren", young_man2, 0,},
		{"������", "gongshusuo", young_man3, 8,},
		{"�Ϲ���",	"nanguoli", cateran, 16,},
		{"�������", "gongsunjiuqiu", banditi, 24,},
		{"��������",	"wangsunxuxie", cateran, 32,},
		{"�Ϲ���",	"nangongban", cateran, 40,},
		{"�����", "gongyangdu", young_man4, 48,},
		{"������",	"ximensong", cateran, 56,},
		{"��԰��", "dongyuanwang", banditi, 61,},
		{"������", "beimangqi", banditi, 66,},
		};

	int lvl = query("index");
	
	if(lvl < 1 || lvl > 10)
	{
		lvl = random(100);

		for(int i=10; i > 0; i--)
		{
			if(mon[i - 1].chance <= lvl)
			{
				lvl = i;
				break;
			}
		}
	}
	set("index", lvl);
	set("idx",random(4));
	lvl = lvl - 1;

	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("no_kill",1);

	set("age", 40 + lvl);
	set("gender", "����");

	set("mfnpc_lvl", 10 + lvl);
	set("nkgain", 30 + lvl * 5);

	set("chat_chance_combat", 20);
	carry_object("sword_1")->wield();
	set("chat_chance", 80);
	call_out(do_die, 7200);

};

void eat_yao(char * yaopin)
{
	char msg[40];
	CContainer * yao = load_item(yaopin);
	yao->move(this);
	command(snprintf(msg, 40, "use %ld", yao->object_id()));
}

virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("sword poqi", 1);
		break; 
	case 1:
		perform_action("sword pojian", 1);
		break;
	case 2:
		perform_action("sword pozhang", 1);
		break;
	case 3:
		perform_action("sword poqiang", 1);
		break;
	case 4:
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
	this->do_copyme(me);
	((CUser *)this)->Ready_PK();
	this->kill_ob(me);
	me->kill_ob(this);	
	return 1;
}

void do_copyme(CChar * ob)
{
	
	set("str", ob->query("str"));
	set("int", ob->query("int"));
	set("con", ob->query("con"));
	set("dex", ob->query("dex"));
	
	set("max_hp",ob->query("max_hp"));
	set("eff_hp",ob->query("max_hp"));
	set("hp", ob->query("max_hp"));
	set("max_mp", int(ob->query("max_mp")*1.2));
	set("mp",  int(ob->query("max_mp")*1.2));
	set("mp_factor", int(ob->query("mp_factor")*1.2));
	set("combat_exp", int(ob->query("combat_exp")*1.2));
	set("level",ob->query("level"));

	int i=20+query("kill/level")*10;

	set_skill("cuff", 50+i*3);
	set_skill("force", 50+i*3);
	set_skill("dodge", 50+i*3);
	set_skill("parry", 50+i*3);
	set_skill("sword", 50+i*3);
	set_skill("strike",50+i*3);
	set_skill("unarmed", 50+i*3);
	set_skill("zixia_shengong", 50+i*3);
	set_skill("poyu_quan", 50+i*3);
	set_skill("huashan_sword", 50+i*3);
	set_skill("hunyuan_zhang", 50+i*3);
	set_skill("lonely_sword", 50+i*3);
	set_skill("huashan_shenfa",50+i*3);
	set_skill("literate", 50+i*3);
	set_skill("zhengqijue", 50+i*3);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("strike", "hunyuan_zhang");
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
	
	static char bnline1[24][20]={"������ʯ���1","�������Ź㳡","���̵���Ů��","�������Ź㳡","������ʯ���1","������ʯ���2","����ɽ��","������ʯ���3","����������","�����һ����Ʒ�","������ʯ���7","������ʯ���8","������ʯ���9","���̺��������","������ʯ���9","������ʯ���8","������ʯ���7","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","���̷���","���̹㳡","���̴��"};
	static char bnline2[24][20]={"������ʯ���1","�������Ź㳡","������������","�������Ź㳡","������ʯ���1","������ʯ���2","����ɽ��","������ʯ���3","����������","�����һ����Ʒ�","������ʯ���7","������ʯ���8","���̾�ľ�����","������ʯ���8","������ʯ���7","�����һ����Ʒ�","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","���̹㳡","��������","���̹㳡","���̴��"};
	static char bnline3[24][20]={"������ʯ���1","�������Ź㳡","������������","�������Ź㳡","������ʯ���1","������ʯ���2","����ɽ��","������ʯ���3","����������","�����һ����Ʒ�","������ʯ���4","������ʯ���5","������ʯ���6","���̺�ˮ�����","������ʯ���6","������ʯ���5","������ʯ���4","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","���̷���","���̹㳡","���̴��"};
	static char bnline4[24][20]={"������ʯ���1","�������Ź㳡","���̵�������","�������Ź㳡","������ʯ���1","������ʯ���2","����ɽ��","������ʯ���3","����������","�����һ����Ʒ�","������ʯ���4","������ʯ���5","������������","������ʯ���5","������ʯ���4","�����һ����Ʒ�","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","���̹㳡","��������","���̹㳡","���̴��"};

	static char bnline11[24][20]={"������ʯ���5","������ʯ���6","���̺�ˮ�����","������ʯ���6","������ʯ���5",	"������������","������ʯ���5","������ʯ���4","�����һ����Ʒ�","����������","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","�������Ź㳡","������������","�������Ź㳡","���̵�������","�������Ź㳡","������������","�������Ź㳡","���̵���Ů��","���̹㳡","���̴��"};
	static char bnline12[24][20]={"������ʯ���5","������ʯ���4","�����һ����Ʒ�","������ʯ���7","������ʯ���8","���̾�ľ�����","������ʯ���8","������ʯ���9","���̺��������","������ʯ���9","������ʯ���8","������ʯ���7","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","��������","���̹㳡","���̷���","���̹㳡","������΢��","���̹㳡","���̹㳡","���̴��"};
	static char bnline13[24][20]={"������ʯ���5","������ʯ���4","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","���̷���","���̹㳡","��������","���̹㳡","���̴��",	"������΢��","�����һ������","�����һ����Ʒ�","����������","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","�������Ź㳡","������������","���̵�������","���̹㳡","���̴��"};
	static char bnline14[24][20]={"������ʯ���5","������ʯ���4","�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","��������","���̹㳡","���̷���","���̹㳡","���̴��","������ʯ���1","�������Ź㳡","���̵���Ů��","�������Ź㳡","������������","�������Ź㳡","������������","�������Ź㳡","���̵�������","�������Ź㳡","������΢��","���̹㳡","���̴��"};

	static char bnline21[24][20]={"�����һ����Ʒ�","����������","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","�������Ź㳡","���̵�������","�������Ź㳡","������������","�������Ź㳡","���̵���Ů��","�������Ź㳡","������������","������ʯ���5","������ʯ���6","���̺�ˮ�����","������΢��","���̹㳡","���̷���","���̹㳡","��������","���̹㳡","���̴��"};
	static char bnline22[24][20]={"�����һ����Ʒ�","����������","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","�������Ź㳡","���̵���Ů��","�������Ź㳡","������������","�������Ź㳡","���̵�������","�������Ź㳡","������������","������ʯ���8","������ʯ���9","���̺��������","������΢��","���̹㳡","���̷���","���̹㳡","��������","���̹㳡","���̴��"};
	static char bnline23[24][20]={"�����һ����Ʒ�","�����һ������","������΢��","���̹㳡","���̷���","���̹㳡","��������","���̹㳡","���̴��","���̹㳡","������΢��","�����һ������","�����һ����Ʒ�","����������","������ʯ���3","����ɽ��","������ʯ���2","������ʯ���1","�������Ź㳡","������������","���̵�������","������΢��","���̹㳡","���̴��"};
	static char bnline24[24][20]={"�����һ����Ʒ�","������ʯ���4","������ʯ���5","������������","������ʯ���5","������ʯ���6","���̺�ˮ�����","������ʯ���6","������ʯ���5","������ʯ���4","�����һ����Ʒ�","������ʯ���7","������ʯ���8","���̾�ľ�����","������ʯ���8","������ʯ���9","���̺��������","������ʯ���9","������ʯ���8","������ʯ���7","�����һ����Ʒ�","������΢��","���̹㳡","���̴��"};

	CRoom * troom;
	switch(query("idx"))
	{
	case 0:
		switch(query("kill/level"))
		{
		case 0:
			troom=load_room(bnline1[i]);
			break;
		case 1:
			troom=load_room(bnline11[i]);
			break;
		case 2:
			troom=load_room(bnline21[i]);
			break;
		case 3:
			troom=load_room(bnline1[i]);
			break;
		case 4:
			troom=load_room(bnline11[i]);
			break;
		case 5:
			troom=load_room(bnline21[i]);
			break;
		case 6:
			troom=load_room(bnline11[i]);
			break;
		case 7:
			troom=load_room(bnline21[i]);
			break;
		case 8:
			troom=load_room(bnline1[i]);
			break;
		}
	case 1:
		switch(query("kill/level"))
		{
		case 0:
			troom=load_room(bnline2[i]);
			break;
		case 1:
			troom=load_room(bnline12[i]);
			break;
		case 2:
			troom=load_room(bnline22[i]);
			break;
		case 3:
			troom=load_room(bnline2[i]);
			break;
		case 4:
			troom=load_room(bnline12[i]);
			break;
		case 5:
			troom=load_room(bnline22[i]);
			break;
		case 6:
			troom=load_room(bnline12[i]);
			break;
		case 7:
			troom=load_room(bnline22[i]);
			break;
		case 8:
			troom=load_room(bnline2[i]);
			break;
		}
	case 2:
		switch(query("kill/level"))
		{
		case 0:
			troom=load_room(bnline3[i]);
			break;
		case 1:
			troom=load_room(bnline13[i]);
			break;
		case 2:
			troom=load_room(bnline23[i]);
			break;
		case 3:
			troom=load_room(bnline3[i]);
			break;
		case 4:
			troom=load_room(bnline13[i]);
			break;
		case 5:
			troom=load_room(bnline23[i]);
			break;
		case 6:
			troom=load_room(bnline13[i]);
			break;
		case 7:
			troom=load_room(bnline23[i]);
			break;
		case 8:
			troom=load_room(bnline3[i]);
			break;
		}
	case 3:
		switch(query("kill/level"))
		{
		case 0:
			troom=load_room(bnline4[i]);
			break;
		case 1:
			troom=load_room(bnline14[i]);
			break;
		case 2:
			troom=load_room(bnline24[i]);
			break;
		case 3:
			troom=load_room(bnline4[i]);
			break;
		case 4:
			troom=load_room(bnline14[i]);
			break;
		case 5:
			troom=load_room(bnline24[i]);
			break;
		case 6:
			troom=load_room(bnline14[i]);
			break;
		case 7:
			troom=load_room(bnline24[i]);
			break;
		case 8:
			troom=load_room(bnline4[i]);
			break;
		}
	}
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
			message_vision(snprintf(msg, 255, "%s��%sһ����ȣ���ħ���������������������ڡ���",this->name(),target->name()), this);
			if(environment()->query("no_fight"))
			{	
				environment()->set("no_fight", 0l);	//ǿ�ȴ˵ؿ���ս��
			}
			this->do_copyme(target);
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
		if(me->query_temp("fight/is_fighting")  && is_fighting(me)!=is_fighting(this) && EQUALSTR(me->querystr("party/party_name"), "����"))
		{
			int exp_mj=1+query("kill/level")*3;
			me->add_temp("mj/exp",exp_mj);
			int exp=random(100*(query("kill/level")+1))+1;
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY������$HIR%ld$HIY���ʵս���顢$HIR%ld$HIY��Ĺ�ѫֵ��", exp,exp_mj));
		}
		else if(!me->query_temp("fight/is_fighting")  && EQUALSTR(me->querystr("party/party_name"), "����"))
		{
			me->add_temp("mj/exp",1);
			int exp=random(10)+1;
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY������$HIR%ld$HIY��Ĺ�Ħ���顢$HIR1$HIY���������ѫֵ��", exp));
		}
	}
	message_vision("$N���ˡ�", this);
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		env->add(snprintf(msg, 255,"����/%s",this->name(1)),1);
		env->add("����/count",1);
	}
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	me->move(load_room("pk"));
	CContainer * env = me->environment();
	if(env->query("mj/start"))
	{
		env->add(snprintf(msg, 255,"����/%s",me->name(1)),1);
		env->add("����/count",1);
	}
	destruct(me);
}
NPC_END;




