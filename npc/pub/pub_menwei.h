//pub_menwei.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_menwei);

virtual void create()
{
	set_name("����", "men wei" );

	set("icon", young_man1);
	set("nickname", "��ʨ��");
	set("gender", "����" );
	set("age", 22);
	set("long", "���Ǹ��긻��ǿ������������ʮ�����ϡ�");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("max_hp", 1200);
	set("mp", 200);
	set("max_mp", 200);
	set("combat_exp", 9000+random(1000));
	set("score", 12000);
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 30+random(10));
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",20);
	
	add_money(20);
	carry_object("dadao")->wield();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	if( EQUALSTR(ob->querystr("family/family_name"), "����ɽ��"))
	{ 
		return snprintf(msg,255,"����Ц������˵������λ%s�������ˣ�������ɡ���",query_respect(ob));
	}
	if(!ob->query("family/family_name"))
	{ 
		return snprintf(msg,255,"��������Ц�ݵ�˵������λ%s��������ʦ�İɡ�ʦ���������棬������ɡ�",query_respect(ob));
	}
	if( ob->query("repute")>200)
	{ 
		return snprintf(msg,255,"��������һ�ɣ�˵������λ%s���������鷳�İɡ���Ȱ�㲻Ҫ���������",query_respect(ob));
	}
	return "";
}

NPC_END;