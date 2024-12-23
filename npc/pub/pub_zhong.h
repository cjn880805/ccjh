// pub_zhong.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhong);

virtual void create()
{
	set_name("�ӹ���","zhong guzhu" );

	set("icon", young_man4);
	set("gender", "����" );
	set("age", 52);
	set("str", 13);
	set("con", 13);
	set("dex", 13);
	set("per", 13);
	set("int", 13);
	set("long", "�ӹ������źó���һ���������۾��������ߣ�һ��ԲԲ�Ĵ����ȴ����ͼ���һ�飬�����۾������֮�䣬������һ���һ�����еĿհ׵أ���ª�쳣��");
	
	set("attitude", "friendly");
	set("max_mp", 500);
	set("mp", 500);
	set("force_factor", 20);
	set("combat_exp", 35000);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 90);
	set_skill("sword", 100);
	set_skill("force", 90);

	carry_object("qingpao")->wear();
	carry_object("bu_shoes")->wear();
}

void init(CChar * me)
{
 	CNpc::init(me);
	if( userp(me) && !is_fighting()) 
	{
        message_vision("�ӹ�����$N˵������Ҫ��ľ�����ȥ���ɣ�",me);
		kill_ob(me);
	}
}

NPC_END;