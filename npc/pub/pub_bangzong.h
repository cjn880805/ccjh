NPC_BEGIN(CNPub_bangzong);

virtual void create()
{
	set_name("����","bangzong");

	set("icon", cateran);
	set("gender", "����");
	set("title", "�ƺӰ����");
	set("age", 22);
	set("str", 25);
	set("per", 15);
	set("dex", 16);
	set("long", "һ����ĸߴ��׳��������ɱ����һ�������ɷ��ģ����");
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


};


NPC_END;
