//jieyinshi.h
//Lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_jieyinshi);

virtual void create()
{
	set_name("����ʹ","jieyin shi");
	set("long","����һλ�����������ˣ���һ���ײ����ۡ����������´������㡣");
	set("title",  "���̽���ʹ" );
	set("gender", "����");
	set("attitude", "friendly");
	set("icon",young_man1);
	set_weight(50000000);

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_hp", 1450);
	set("hp", 450);
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set("mj",1);
	
	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang_quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	prepare_skill("cuff", "jingang_quan");
	
	carry_object("baipao")->wear();
	set_inquiry("����",ask_for_join);
	set("no_huan",1);
}

static char * ask_for_join(CNpc *who,CChar *me)
{
	return "�н����žͿ��Լ��������̡�";
}

virtual int accept_object(CChar * ob, CContainer * obj)
{
	string msg;
	string men ;
	CMapping * party;

	if (EQUALSTR(obj->querystr("id"), "tuijian xin1") && ob->query_temp("have_letter") )
	{
		party = ob->querymap("party");
		if( party )
		{
			if(DIFFERSTR(ob->querystr("party/party_name"), "����")  )
				message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ��������������̡�",this,ob);
			else
				message_vision("$Nҡҡͷ����$n˵�������Ѿ��������̵����ˡ�",this,ob);
		
			return 1;
		}
				
		if( ob->present("tuijian xin1"))
		{
			if (  EQUALSTR(ob->querystr("gender"), "Ů��") ) 
				men="��";
			else if (  EQUALSTR(ob->querystr("class"), "taoist") 
				||  EQUALSTR(ob->querystr("class"), "bonze") )
				men="��";
			else if ( ob->query("repute") < 0 )
				men="��";
			else
				men="��";

			destruct(obj);
			ob->delete_temp("have_letter");
			
			if (  EQUALSTR(ob->querystr("gender"), "Ů��") )
				say("�������ֵ�һŮ�к��ܣ����ǿ�ϲ�ɺ� !", ob);
			else 
				say("�������ֵ�һӢ�ۺú������ǿ�ϲ�ɺ� !", ob);
			
			CMapping par;

			par.set("party_name", "����");
			men+="���Ž���";
			par.set("rank", men.c_str());
			par.set("level", 1);
			par.set("enter_time", current_time);
			ob->set("party", par);
					
			say(g_Channel.do_emote(this, 0, "smile", 1), ob);
			msg = "��ϲ���Ϊ����";
			msg +=men;
			msg += "��";

			say(msg.c_str(), ob);
			SendMenu(ob);
			
			return 1;
		}
	}

	say(g_Channel.do_emote(this, ob, "?", 1), ob);
	say("�ⶫ�����ҿ�û��ʲ���á�", ob);
	SendMenu(ob);
	return 0;
}

NPC_END;



