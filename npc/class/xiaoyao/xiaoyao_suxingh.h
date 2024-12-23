// xiaoyao_suxingh.c

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNxiaoyao_suxingh);

virtual void create()
{
	set_name("������","su xinghe");
	set("gender", "����" );
	set("nickname", "һ������");
	set("title","��ң�ɵڶ��������");
	set("long","���˾��Ǻų�һ�����˵������ӣ������������Ʊ磬��һ�������е��������ߣ��������书Ҳ��������֪�� ");
	
	set("class", "scholar");
	set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);
 	set("icon",old_man1);
	
	set("no_clean_up",1);
	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);
	
	set("max_hp", 10400);
	set("mp", 3500);
	set("max_mp",3500);
	set("mp_factor", 60);
	set("env/wimpy", 60);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("hand", 180);
	set_skill("lingboweibu", 180);
	set_skill("beiming_shengong", 180);
	set_skill("xiaoyao_dao", 180);
	set_skill("liuyang_zhang", 180);
	set_skill("zhemei_shou", 180);
	set_skill("literate", 180);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("blade", "xiaoyao_dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand","zhemei_shou");
	
	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");	
	
	create_family("��ң��", 2, "����");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
	
	set_inquiry("���ܵص�",ask_me);
	set_inquiry("����ʮ����",ask_book);
	set_inquiry("����һЦ",ask_jl);
	set_inquiry("����",ask_fd);
}

static char * ask_book(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
	{
		return "��Ҫ֪�������콣�����ܾ͵ü�����ң�ɡ�";
	}

	return "���ɵ��书������������ʮ�������ϴ�ʦ��������ֻ�к���֮�������洫������˵������δ�����������콣ʮ�����еľ��硣";
}

static char * ask_fd(CNpc *who,CChar *me)
{
	if ( me->query("xy/renwu1"))
	{
		if(!me->query_temp("xy/renwu1_1"))
			me->set_temp("xy/renwu1_1",1);//����ǰ��������������ѯ�������˹��ڸ��ص���Ϣ
		return "����ֻ��ʦ�������ȴ��֪��������δ���������˵��������������������ң������ԨԴ������ǰ����ѯ������֪һ����";
	}

	return "ʲô��";
}

static char * ask_me(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
	{
		return"��Ҫ֪���ܵ��͵ü�����ң�ɡ�";
	}

	me->set_temp("mask/������", 1);
	return "���ɵ��ܵ����䵱ɽ֮�ϣ����Ǽ��ա���������������ȥ������";
}

virtual void attempt_apprentice(CChar * ob)
{
	
	char msg[255];
	if (ob->query_int() < 30) 
	{
		command(snprintf(msg,255,"shake %ld", ob->object_id() )); 
		say(snprintf(msg,255,"%s�Ƿ�Ӧ����ѧ���϶��µ㹦��",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	
	say(" �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
	ob->set("class", "scholar");
	ob->FlushMyInfo();
}

static char * ask_jl(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
	{
		return"�㲻��������ң�ɵ����ˣ�������Щ��ʲô��";
	}
	if(me->query_temp("xiaoyao/����")==4)
	{
		me->add_temp("xiaoyao/����",1);
		return "������һЦ����ֻ����ʦ��ʹ�ù�һ�Σ���Ѥ����Ŀ���������Ƿ�׹�ĳ��棬�����񶼻��ǵ����������";
	}
	me->set_temp("xiaoyao/����",0l);
    return "�ԴӶ������������������ʦ������֮���Ҿ���Ҳû�м���ʦ�����Ĺ��ˣ�Ҳ��Ҳû�м���ʦ���������ˡ�";
}


NPC_END;





