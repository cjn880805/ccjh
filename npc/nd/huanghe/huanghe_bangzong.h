// bangzong.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_bangzong);

virtual void create()
{
	set_name("��", "da han");
	set("gender", "����");
	set("title", "�ƺӰ����");
	set("age", 22);
	set("str", 25);
	set("per", 15);
	set("dex", 16);
	set("icon",young_man5);	

	set("long", "һ����ĸߴ��׳��������ɱ����һ�������ɷ��ģ����\n");
	set("combat_exp", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("axe", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	
	set("mp", 100); 
	set("max_mp", 100);
	set("mp_factor", 10);
	
	carry_object("cloth")->wear();
}

NPC_END;