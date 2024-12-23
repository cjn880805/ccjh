// shaolin_huogong.c �𹤵���

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_huogong);

virtual void create()
{
	set_name("�𹤵���", "huogong");
	set("gender", "����");
	set("age", 35);
	set("class", "taoist");
	set("long",	"����ȫ����ƹܳ����Ļ𹤵��ˡ�");
	set("attitude", "friendly");
        set("icon",young_man1);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("hp", 300);
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 0l);
	
	set("combat_exp", 15000);
	
	set_skill("force", 50);
	set_skill("xiantian_qigong", 40);    //��������
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 50);   //���㹦
	set_skill("parry", 50);
	set_skill("strike",50);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");

	carry_object("greyrobe")->wear();
	
}

NPC_END;