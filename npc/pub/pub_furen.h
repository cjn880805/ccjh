// pub_furen.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_furen);

virtual void create()
{
	set_name("ׯ����", "zhang furen");

	set("icon", young_woman4);
	set("title", "ׯ����������" );
	set("nickname",  "δ����" );
	set("long",  "ֻ����ԼĪ��ʮ�������,ȫ������,��ʩ֬��,��ɫ�԰ס�");
	set("gender", "Ů��");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 50000);
	
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("sword", 90);
	set_skill("taiji_jian", 80);
	set_skill("tiyunzong",90);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "tiaji_jian");
	map_skill("sword", "tiaji_jian");
	
	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 35);
 	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	set_inquiry("����" , "�������ҼҵĴ���ˡ�");
	set_inquiry("������" ,"��һ��Ҫ���������������");
	set_inquiry("����" ,  "��������ɲ�һ��,�������ҵĺ�Ѿ��˫˫��");
	set_inquiry("˫˫" ,  "��СѾͷ�����Ҷ���,����Ҳ���׵���");

	add_money(250);
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	char msg[255];
	if( userp(me) && !is_fighting() ) 
		say( snprintf (msg,255,"�ܾ�û��������,��λ%s����֪�����๫��������?", query_respect(me) ));
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	int i;
	char msg[255];

	if ( ob->is_character() && EQUALSTR(ob->querystr("base_name"), "wu_zhi_rong") )
	{
		i= me->query("weiwang");

        if(i >= 50 && i < 70)
		{
			i += 10;
			me->set("weiwang", i);
			message_vision( "$N�Ľ�����������ˣ�" , me);
			tell_object(me, snprintf(msg, 255, "�����ڵĽ���������%ld", i));
			say("����,����!�벻����Ҳ�н���!!!");
			((CChar *)ob)->die();
		}

		if(me->query("weiwang")>=70)
		{
			say(snprintf(msg,255, "��λ%s,��˴�����,���ʵ��֪����Ϊ��.",query_respect(me) ), me);
			say("�����Ͷ���һ������,������ȴ����.", me);
		}
	}
	
	if (  EQUALSTR(ob->querystr("name"), "��ʷ����") )
	{
		say(snprintf(msg,255, "��λ%s,��л��.",query_respect(me) ), me);
		say("��,��Ҫ�ܰ����ҵ��������⹷���ͺ���.", me);
	}		

	if (  EQUALSTR(ob->querystr("name"), "ׯ�ʳ�") )
	{
		say(snprintf(msg,255,"��λ%s,��л��.",query_respect(me) ), me);
		say("��,��Ҫ�ܰ����ҵ��������⹷���ͺ���.", me);
	}		

	SendMenu(me);
	return 1;
}

NPC_END;