// pub_yangzong.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_yangzong);

virtual void create()
{
	set_name("����", "yang zong" );

	set("icon", banditi);
	set("long","����һλ����ͬ����");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	
	set("combat_exp", 5000);
	set("score", 1000);
	
	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	carry_object("shuzhi")->wield();
	carry_object("sengmao")->wear();
	carry_object("sengxie")->wear();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"���ں�ʲΪ��˵��������٢��%s��ƶɮ���������ˡ�",query_respect(ob) );
}
NPC_END;