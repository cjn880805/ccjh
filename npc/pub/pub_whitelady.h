//pub_whitelady.c 
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_whitelady);


virtual void create()
{
	set_name("������Ů","white lady" );

	set("icon", young_woman4);
	set("gender", "Ů��" );
	set("age", 18);
	set("long", "һ�����������İ�����Ů��");
	set("shen_type", -1);
	set("combat_exp", 1000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_hp", 300);
	set("mp", 100);
	set("max_mp", 100);
	set("score", 800);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	create_family("����ɽ��", 10, "����");
        set_inquiry("����ׯ��","ÿ���˶�˵���ǻ��ˣ����Լ�Ҳ˵�Լ��ǻ��ˣ������һ��Ǿ������˺ܺá�");
	carry_object("baipao")->wear();
}

/*
virtual char * greeting(CChar * ob)
{
	char msg[255];
	return snprintf(msg,255,"������Ů������˵������λ%s������������һ����׽�Բذɡ�",query_respect(ob) );
}
*/

NPC_END;