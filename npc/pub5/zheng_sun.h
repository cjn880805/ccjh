//zheng_sun.h �ﲻ��


NPC_BEGIN(CNzheng_sun);

virtual void create()
{
	set_name("��˵һ", "sun suoyi");
	set("gender", "Ů��");
	set("age", 33);
	set("class", "taoist");
	set("nickname", "�徻ɢ��");
	set("long",  "������ȫ��̶���������Ψһ��Ů������˵һ�����ˡ��������������ǰ�����ӣ�����������һ������ͷ��");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 29);
	set("con", 29);
	set("dex", 29);
	set("foolid",35);
	set("title","ȫ������֮ĩ");
	set("chat_chance_combat", 60);
	
	set("hp", 4000);
	set("max_hp", 12000);
	
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 180);
	set_skill("sword", 180);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("unarmed",180);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 200);    //��������
	set_skill("quanzhen_jian",200);  //ȫ�潣
	set_skill("jinyan_gong", 180);   //���㹦
	set_skill("haotian_zhang", 200);    //�����

	set_skill("literate",160);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 2, "����");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
}
void die()
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
NPC_END;



