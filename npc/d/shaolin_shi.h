// shaolin_shi.c ľһ��

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_shi);

virtual void create()
{
	set_name("ľһ��",  "shi shuangying");
	set("title",  "�컨��ʮ������" );
	set("nickname",  "�����" );
	set("long", "�����ľһ���ڻ�������ʮ���ѽ��Σ�ִ�����ã�������˽���ĺ����������˹����ľ����ӵ����ĺ��ǣ���Ҳ������ץ�����̣����Ժ컨�������ֵܣ��ᵽ�����ʱ�޲��Ȼ��");
	set("gender", "����");
	set("class", "scholar");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
        set("icon",young_man4);
	
	set("max_hp", 4500);
	set("hp", 1500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 200000);
	
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("parry", 90);
	set_skill("sword", 90);
	set_skill("taiji_quan", 95);
	set_skill("taiji_shengong", 90);
	set_skill("taiji_jian", 90);
	set_skill("tiyunzong", 90);
	
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji_shengong");
	map_skill("unarmed", "tianji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	set("env/wimpy", 20);
	create_family("̫����",8, "����");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

NPC_END;