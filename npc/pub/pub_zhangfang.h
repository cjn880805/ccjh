// pub_zhangfang.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhangfang);

virtual void create()
{
	set_name("�˷��Ϸ���","lao fuzi" );

	set("icon", drugstore_boss);
	set("gender", "����");
	set("age", 56);
	set("long","����һ����Ǯ�ۿ������˷���������˪������͸��һ˿�ƻ���");
	
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("eff_hp",2000);
	set("hp",2000);
	set("max_mp", 1000);
	set("mp", 1000);
	set("mp_factor", 100);
	set_skill("force", 200);
	set_skill("unarmed", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);
 	carry_object("cloth")->wear();

	set_inquiry ("ѧ��"  , "�Ƚ���ٽ�");
	set("no_huan",1);
	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
/*    if (who->query("combat_exp")>= 10000)	//ԭ��3500̫�١�lanwood 2001-02-24
    {
        say("����书Ӧ���������������ٳ�����������û�������ˡ�", who);
		SendMenu(who);
		return 0;
    }
*/
    if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 500)
    {
        who->set_temp("marks/jinniu_paied",1);
        say(snprintf(msg,255,"�ã���Ȼ��λ%s����Ͻ����Ǿ���ʦ��ѧ�ɣ�" ,query_respect(who) ), who);
		SendMenu(who);
		destruct(ob);
       	return 1;
    }
    
    say("������Ҳ̫���˵���ɣ�", who);
	SendMenu(who);
	return 0;
}

NPC_END;