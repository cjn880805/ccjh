//miejue.h
//Lanwood 2000-01-06

ZUSHI_BEGIN(CNemei_miejue);

virtual void create()
{
	set_name("��ʦ̫", "miejin shitai");
	set("long", "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�");
	set("gender", "Ů��");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 100000);
	set("class", "bonze");
	set("chat_chance_combat", 60);
	set("icon", taoistess);
	set("foolid",13);
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);
	
	set("hp",22000);
	set("max_hp", 22000);
	
	set("mp", 14000);
	set("max_mp", 14000);
	set("mp_factor", 200);
	
	set("combat_exp", 60000000);
	set("score", 1000);
	set_skill("persuading", 150);
	set_skill("throwing", 220);
	set_skill("force", 290);
	set_skill("dodge", 250);
	set_skill("finger", 250);
	set_skill("parry", 250);
	set_skill("strike", 290);
	set_skill("sword", 280);
	set_skill("blade", 250);
	set_skill("literate", 180);
	set_skill("mahayana", 250);
	set_skill("buddhism", 250);
	set_skill("jinding_zhang", 250);
	set_skill("tiangang_zhi", 250);
	set_skill("huifeng_jian", 280);
	set_skill("yanxing_dao", 220);
	set_skill("zhutian_bu", 250);
	set_skill("linji_zhuang", 250);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("blade","yanxing_dao");
	map_skill("parry","huifeng_jian");
	//        map_skill("magic","bashi-shentong");
	create_family("������", 3, "������");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_talk",1);
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	perform_action("sword mie");
	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	
	if (DIFFERSTR(me->querystr("family/family_name"), "������"))
    {
		say(snprintf(msg, 255, "%s�뱾��������������֪�˻��Ӻ�̸��", query_respect(me)), me);
		SendMenu(me);
		return;
    }

   if(random(2))
   {
       if (DIFFERSTR(me->querystr("class"), "bonze") )
       {
           say("�����ӷ�ƶ�᲻���׼ҵ��ӡ�", me);
		   SendMenu(me);
           return;
       }
       else
       {
           say("�����ӷ�ƶ�᲻�յ��ӡ�", me);
		   SendMenu(me);
           return;
       }
   }

   if (me->query_skill("mahayana", 1) < 90 || me->query_skill("linji_zhuang", 1) < 90)
   {
		say("�㱾�ŵĹ�����Ϊ��̫�͡�", me);
		SendMenu(me);
		return;
   }

   if (me->query("repute") < 50000)
   {
		say(snprintf(msg, 255, "%s����������֮�»����Ĳ�����", query_respect(me)), me);
		SendMenu(me);
		return;
   }

   if (EQUALSTR(me->querystr("class"), "bonze") )
   {
	   char name[5], new_name[5];

       strncpy(name, me->name(1), 4)[4] = 0;
       snprintf(new_name, 5, "��%s", &name[2]);
		
	   me->set_name( new_name);
       say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s����ϲ���Ϊ���ҵ��Ĵ�����!", new_name));
   }

   say("�����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
   say("ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
   command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}

int ask_for_quit(CChar * me)
{
    if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
	{
        say("��Ͷ���û��ԨԴ��ƶ�᲻�Ҹ��㻹�ס�", me);
		SendMenu(me);
		return 1;
	}

    if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("�����ӷ𣡳����˲���ڿ����Ѿ����׼����ˡ�", me);
		SendMenu(me);
		return 1;
	}

    me->set_temp("pending/quit_bonze", 1);
    say("�����ӷ����գ����գ���һ��Ҫ���ף���Ҳ��������", me);
    say("�ҽ���ȥ�㲿���书�������������", me);
    say("�����Ը���׵ģ��Ͱ����ڴ������ɡ�", me);

	AddMenuItem("��������", "$0kneel $1", me);
	AddMenuItem("ת���뿪", "", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
		return do_kneel(me);	
	else if(strcmp(comm, "agree") == 0)
		return do_agree(me);

	return CNzushi::handle_action(comm, me, arg);
}

//ԭ�ļ�ȱʧ���˴���Lanwood���䡣2001-01-06
int do_kneel(CChar * me)
{
	char msg[255];
    if( ! me->query_temp("pending/quit_bonze") ) return 0;

    message_vision("$N�������ϵĵ��ۣ����������ع��������˼�����ͷ���Ӵ˻ָ���������", me, this);
    
	me->delete_temp("pending/quit_bonze");
	me->set_name(me->querystr("bonze/old_name"));
	me->set("repute", "shen_record");
	me->del("class");
	me->del("K_record");
	me->del("shen_record");
	me->del("bonze/old_name");
	
	me->UpdateMe();

	say(snprintf(msg, 255, "�ӽ��Ժ���ָ���ǰ���׼����գ�����%s��", me->name()), me);
    say(g_Channel.do_emote(this, 0, "sigh", 1), me);
	SendMenu(me);

    return 1;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "������" ))
	{
		if(strcmp(ask, "����") == 0)
			return ask_for_quit(me);	
		else if(strcmp(ask, "�뿪") == 0)
			return ask_for_leave(me);
		else if(strcmp(ask, "����") == 0)
		{
			const char * ptr = ask_zhangmen(this, me);
			if(ptr)
			{
				say(ptr, me);
				SendMenu(me);
			}			
			return 1;
		}

        AddMenuItem("����ʦ̫�����ס�", "����", me);
		AddMenuItem("����ʦ̫�����뿪�����ɡ�", "�뿪", me);
		AddMenuItem("����ʦ̫��������֮λ", "����", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int ask_for_leave(CChar * me)
{
	if(DIFFERSTR(me->querystr("family/family_name"), "������"))
		return 0;

	me->set_temp("pending/betray", 1);
	say("�����ִ����ɽ��ƶ��ȴ�м��仰˵��", me);
	say("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��?", me);
	AddMenuItem("��Ը�⡣", "$0agree $1", me);
	AddMenuItem("��֪���ˡ�", "", me);
	SendMenu(me);
    return 1;
}

int do_agree(CChar * me)
{
	if(! me->query_temp("pending/betray")) return 0;

	me->delete_temp("pending/betray");
	
    me->add("betray/emei", 1);
    me->add("betray/count", 1);
    me->set("combat_exp", int(me->query("combat_exp") * 0.95));
	
	while(query_valid_exp() < 0)
	{
		add("level", -1);
		setup_char(this);
	}

	CMapping * skills = me->query_skills();
	CVector v;
	skills->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		if((*skills)[v[i]]>351) 
			(*skills)[v[i]] = 351;
	}
	
	me->FlushMySkill(me);
	me->release_master();
	me->del("zhangmen");
    me->del("family");
    me->del("class");
    me->set("title", "��ͨ����");
    
	me->Save();
	me->UpdateMe();

	say("�������뱾����Ե�������ɽȥ�ɣ�", me);
    say("�����粨���ƶ����Σ�����Ϊ֮������", me);
	SendMenu(me);
    return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if (DIFFERSTR((who->environment())->querystr("base_name"), "���һ����ֺ��" ))
		return notify_fail("�����������");
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
ZUSHI_END;
