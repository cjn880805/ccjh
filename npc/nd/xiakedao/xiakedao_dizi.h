NPC_BEGIN(CNxiakedao_dizi);

virtual void create()
{
	set_name("����","dizi");

	set("icon", triggerman2);
	set("long", "������ʮ�����׳���������Բ���ǵ�������ԭ��ļ���ġ�");
	
	set("gender", "����");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("hp", 500);
	set("max_hp", 1500);
	set("hp", 200);
	set("max_hp", 600);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	
	set("combat_exp", 30000);
	set("score", 10);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("staff", 50);
	create_family("���͵�", 2, "����");
//	carry_object("cloth")->wear();
			
};

NPC_END;
