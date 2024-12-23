//pub_shizhe3.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_shizhe3);

virtual void create()
{
	set_name("����",  "shi zhe");

	set("icon", waiter);
	set("title", "���͵����ӵ���");
	set("gender", "����" );
	set("age", 30);
	set("long","���Ǹ����Ż��µ���ʮ���꺺�ӣ�����վ�������ޱ��顣");
	set("attitude", "friendly");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 990);
	set("mp", 300);
	set("max_mp", 300);
	
	set("combat_exp", 10000);
	set("score", 10000);
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 40);
	
	create_family("���͵�", 2, "����");
	
	set_inquiry("here","������������е������ˣ�С�������������ô�ã������е�����Ҳ���������");
	set_inquiry("cha","�����Դ�����������С�����ڲ����뿪�˵أ�");
	set_inquiry("yezi","�����Դ�����������С�����ڲ����뿪�˵أ�");
	
	carry_object("cloth")->wear();
//	carry_object("key1")->wear();
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"��λ%s�����Ҳ���������������ܵİɡ�������������е������ģ����������ȥ�ۿ�����һ��ҪС�����⣬ǧ�򲻿�çײ���¡����ҿɹ�Ӧ��ʳ���������Ǿ�����ȥΪ�á�",query_respect(ob) );
	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	command("smile");
	
	if( EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000  )
	{
		say(snprintf(msg,255," %s��˹ŵ��ȳ������������գ���������������˵�ģ�����ʵ�ڲ����ļ������ȡ���������Ž�ȥ����ǽ���ϵ��ǰ�ľ��ȡ�£��������ϣ������кô�������ǧ�����߱��ˣ��������Ҷ���ɱ��֮�����м��мǣ�����" ,query_respect(who) ), who);
		SendMenu(who);
	}
	destruct(ob);
	return 1;
	
}

virtual void die()
{
	say("���ɱ�ң����ӵ�����Ҳ����Ź��㡣");
		
	//message_vision("������������ˤ����һ�ԣ���ʱ��ŷ��ָղ���վ�ĵط��е���֡��ذ�������ʯ����ɣ��ƺ��Ǹ���.���滹��һԿ�׿�(kong) ", this);
	
	CNpc::die();
}

NPC_END;