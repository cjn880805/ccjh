//pub_feifei.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_feifei);

virtual void create()
{
	set_name("�ʷ�","fei fei" );

	set("icon", triggerman2);
	set("gender", "����" );
	set("age", 35);
	set("long", "һ����ͷ����ĳ�ʦ����ֻС�۾���ͣ��գ���š�");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	add_money(500);
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];

	if(( EQUALSTR(ob->querystr("family/family_name"), "����ɽ��"))&&(random(3)==1))
	{
		return snprintf(msg,255,"�ʷ�Ц������˵������λ%s�����˰ɣ����ò͡�",query_respect(ob));
	}
	 
	return snprintf(msg,255,"�ʷ�С��һգ��Ц������˵������λ%s����ӭ���ιۣ��ɲ�Ҫ͵��Ӵ��",query_respect(ob));
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[40];

//	if ( !(who->Present(ob)) ) return notify_fail("��û�����������");

	if ( DIFFERSTR(ob->querystr("base_name"), "mu_chai") )
	   return notify_fail("�ʷʲ�Ҫ���������");

	command(snprintf(msg, 40, "smile %ld", who->object_id() ));
	if (random(3)==1)
	{
		CMoney::Pay_Player(who, 1200);
		tell_object(who,"�Ҷ����������ӣ���Ҫ���ţ�");
	}
	else
	{
		CMoney::Pay_Player(who, 1000);
		tell_object(who,"�ٽ��������Ժ��һ����ô��ģ�");
	}
	return 1;
}


NPC_END;