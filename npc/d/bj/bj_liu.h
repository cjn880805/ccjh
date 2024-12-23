//bj_liu.c ������

NPC_BEGIN(CNbj_liu);

virtual void create()
{
	set_name("����", "liu");
	set("gender", "����");
	set("age", 38);
	set("class", "taoist");
	set("long", "����������������������ȫ���ɵ��Ĵ����ӡ�");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 30);
	set("con", 28);
	set("dex", 30);
	
	set("foolid",29);
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("sword", 220);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 220);    //��������
	set_skill("quanzhen_jian",220);  //ȫ�潣
	set_skill("jinyan_gong", 200);   //���㹦
	set_skill("haotian_zhang", 220);    //�����

	set_skill("literate",160);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 4, "����");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("chat_chance", 30);
	
}

virtual char * chat_msg()
{
	if(!query_temp("fight/is_fighting") && query("temp"))
	{
		destruct(this);
		return 0;
	}
	return 0;
}
void die()
{
	if(((environment())->environment())->query("boss"))
	{
		CFightRoom * obj=(CFightRoom *)environment();
		revive(1);
		message_vision("\n$N���Ʋ��룬һ�������������У������׷����ֻ����������ӭ�������ֻ�����գ��Ա�һ���������ϡ�", this);
		obj->add("zheng/count",-1);
		
		if(EQUALSTR(obj->querystr("zheng/friend1_name"), this->name(1)))
		{
			obj->del("zheng/friend1_idx");
			obj->del("zheng/friend1_name");
		}
		else if(EQUALSTR(obj->querystr("zheng/friend2_name"), this->name(1)))
		{
			obj->del("zheng/friend2_idx");
			obj->del("zheng/friend2_name");
		}
		else
		{
			obj->del("zheng/friend3_idx");
			obj->del("zheng/friend3_name");
		}
		destruct(this);
	}
	else
		CNpc::die();
}

void init(CChar * me)
{
	CNpc::init(me);
	if (!userp(me)) 
	{
		this->kill_ob(me);	
		me->kill_ob(this);
	}
}

NPC_END;



