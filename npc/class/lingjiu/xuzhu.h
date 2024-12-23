//xuzhu.h
//Lanwood 2000-01-08

NPC_BEGIN(CNlingjiu_xuzhu);

virtual void create()
{
	set_name("����", "zhu xu");
	set("long",	    "����һ����ʮ�������������, Ũü����,���ı��ӱ�ƽ����, ��ò��Ϊ��ª. ");
	set("title", "���չ�����");
	set("gender", "����");
	set("per", 16);
	set("age", 26);
	set("nickname", "����");
	set("shen_type",1);
	set("attitude", "peaceful");
	set("icon",young_man1);

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("max_hp", 12000);
	
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 2500000);
	set_skill("force", 220);
	set_skill("unarmed", 250);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("hand",220);
	set_skill("strike", 220);

	set_skill("zhemei_shou",220);
	set_skill("liuyang_zhang",220);
	set_skill("yueying_wubu",200);
	set_skill("bahuang_gong", 230);
    set_skill("tianyu_qijian", 220);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword", "tianyu_qijian");

//	set_inquiry("������", ask_me);
	
	set("ling_count", 1);

	prepare_skill("strike", "liuyang_zhang");
	prepare_skill("hand", "zhemei_shou");
	create_family("���չ�",2,"����");
	set("chat_chance_combat", 50);
	
	carry_object("changjian")->wield();
 	carry_object("changpao")->wear();
    carry_object("jiudai");
    add_money(5000);
	set("no_talk",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];
	if(userp(me) && !is_fighting() && me->query("lj/renwu13") && EQUALSTR(me->querystr_temp("apply/name"),"����"))
	{
		CContainer * env=me->environment();
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(userp(target))	continue;
			if(EQUALSTR(target->querystr("name"), "��������")  && EQUALSTR(target->querystr("owner"),me->id(1)))
			{
				target->set_leader(0);
				message_vision("\n$HIR��������������ǰ�������飬���ȵ�˵����������",me);
				me->set_temp("lj/end",1);
				break;
			}
		}
		if(me->query_temp("lj/end"))
		{
			//�������
			DTItemList * list = me->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj = list->GetNext(p);
				if(obj->is_character()) continue; 
				CChar * target = (CChar *)obj;  
				if(userp(target))	continue;
				if(EQUALSTR(target->querystr("apply/name"),"����") && EQUALSTR(target->name(1),"������Ƥ���")
					&& EQUALSTR(target->querystr("����"),me->id(1)) && EQUALSTR(target->querystr("id"),"killermask"))
				{
					me->delete_temp("apply/name");
					me->delete_temp("apply/id");
					me->delete_temp("apply/long");
					me->delete_temp("apply/short");
					me->delete_temp("apply/icon");
					me->delete_temp("apply/title");

					destruct(target);
					me->UpdateMe();
					break;
				}
			}
			message_vision("\n$HIR��������Ƥ��ߣ�¶��ԭ������Ů�Ե��������ӣ��Թ���ǸȻһЦ����������ð���ˣ�������",me);
			message_vision("$HIR��ʵ�������������չ�����������������������ȴ�������飬�Ҳ����ǻ�Ե�ɺ���ð����������Щ�𰸵Ļ�Ҳ���������ҵ�����",me);
			message_vision("$HIR�����������������ж������Ե������Ҳ���ؾ���һ�𣡡�",me);
			message_vision("\n$HIR�������������૵������������ô�����ɣ���",me);
			message_vision("\n$HIR���鿴�Ź�����˫�����������",me);
			message_vision("$HIR��������˵--������һ���ڣ����ⳡ�α����ˡ������ҵ��������ɣ��ҽ��㡮���ɡ������ɣ����ɣ���˵�����ֺò��ã�",me);
			message_vision("$HIR�������ȴ�����ˣ�������ɻ�����վ������ǰ������",me);
			message_vision("$HIR˵�գ��㽫����ӵ�뻳�С���������һ����Ҳ��ͷ������������ǰ����",me);
			message_vision("\n$HIR�㿴�Ŷ�����˶����������Ĵ��ţ�ĬĬ�߿��ˣ������жԡ����顱������������һ�㡭��\n",me);
			
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s����%s(%s)$HIY��װ��磬ǧ������ǰ�����Ļʹ��μӱ������ף��������ؿ��飬���ڳ�ȫһ�Ρ������Ե���ļѻ���$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));
			//��ɡ������Ե�����񣬽���10������ָ
			if(me->query_skill("rouqing_zhi",1)<600)
				me->set_skill("rouqing_zhi",me->query_skill("rouqing_zhi", 1)+10);
			me->del("lj");
			me->delete_temp("lj");
			me->FlushMySkill(me);
		}
		
	}
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * jian = PresentName("changjian", IS_ITEM);

	switch(random(8))
	{
	case 0:
			perform_action("strike zhong", 1);
			break;
	case 1:
			perform_action("hand duo", 1);
			break;
	case 2:
			perform_action("sword san", 1);
			break;
	case 3:
	case 4:
			if(query_weapon() == jian && jian)
				command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
			break;
	case 5:
	case 6:
			if(jian && ! query_weapon())
				command(snprintf(msg, 40, "wield %ld", jian->object_id()));
			break;
	case 7:
	case 8:
			perform_action("force recover", 0);
			break;
	}
	
	return 0;
}

static char * ask_me(CNpc * me, CChar * who)
{
	if (DIFFERSTR(who->querystr("family/family_name"), "���չ�"))
			return "���뱾��������������֪�˻��Ӻ�̸��";

	if (me->query("ling_count") < 1)
		return "�����ò���ʱ���Ѿ������������ˡ�";

	CContainer * ob = load_item("lingjiu");
	ob->move(who);
	me->add("ling_count", -1);

	message_vision("�����$Nһ��$n", who, ob);
	return "��ȥ�ɡ�";
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( me->query_skill("bahuang_gong", 1) < 150) 
    {
		say(snprintf(msg, 255, "%s�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�", query_respect(me)), me);
		SendMenu(me);
		return;
	}  

    if (EQUALSTR(me->querystr("gender"), "Ů��"))
    {
		message_vision("���鴹Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���", me);
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("class", "officer");
		me->UpdateMe();
        return;
	}
   
	say("��������㿴�˰���,˵���������²������������ҵ�MM��?��", me);
	SendMenu(me);
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query("lj/renwu_ok") && !me->query_temp("lj/renwu_ok_xz"))
	{
		tell_object(me, "\n$HIR����̾�˿�����˵������������������̫���ˣ�����Ȱ��ʦ���ʦ�������������������ܾ��ˡ�");
		tell_object(me, "$HIR���Ѱ�ʦ���ͻ����ˣ�������ֱ���˵Ķ����ܶ��ˣ���˵�����뻯���Թ���������Σ�");
		tell_object(me, "$HIR������");
		tell_object(me, "$HIRʦ���������ڱչ������˰ɣ���˵��һ�����л��ģ�����ȥ����һ�档��\n");
		me->set_temp("lj/renwu_ok_xz",1);
		
		if(EQUALSTR(me->querystr("gender"), "Ů��") && EQUALSTR(me->querystr("family/family_name"), "���չ�") )
		{
			tell_object(me, "\n$YEL��������ȥ����Ȼ�����ֽ���ס����ЩŤ����ʵ���");
			tell_object(me, snprintf(msg, 255,"$YEL��%s�������ڻ���ʦ��ȥ���ĵ�·�ϡ�����û����ʦ���ᵽ���С����ιá�����Ů�ӣ���",me->name(1)));
			tell_object(me, "$YEL���ͷ�������Ŷ���ǵ�û�У���ʱ�������׷�ȵ�����������û������˵�����ġ���");
			tell_object(me, "$YELֻ���������Ϻ�������ʧ�������飬�ճյ��������ιá�������ϲ����Ů�ӡ��������֪����������Ļ�������ظ�֪����");
			tell_object(me, "$YEL�㲻�ɵ�����������ѵ����������Ĵ����⼸��ͻ��������ˣ�����ȴ˵�������岻�ݴǣ���");
			tell_object(me, "$YEL������¶��ο֮ɫ�����������ұ㲻������ȥ�������ˣ���\n");
			me->set("lj/renwu10",1);
		}
	}
	else if(me->query("lj/renwu_lost"))
	{
		if(me->query("lj/renwu_lost")==1)
		{
			tell_object(me, "$HIW����ʹ���˵������ʲô����Ůͯ��������ʦ�������㾹Ȼ�������ȳ������ҿ������ˣ���");
			me->del("lj");
			me->delete_temp("lj");
			me->set("hp",100);
			me->set("eff_hp",100);
			me->set("mp",0l);
			if(me->query("level")<80)
			{
				me->add("combat_exp",-me->query("level")*200);
				message_vision(snprintf(msg, 255, "$HIR$Nִ���������������Ե���У�������������������ʧ�ܡ�\n$N���������½�%d�㡣",me->query("level")*200),me);
			}
			else
			{
				me->add("combat_exp",-me->query("level")*500);
				message_vision(snprintf(msg, 255, "$HIR$Nִ���������������Ե���У�������������������ʧ�ܡ�\n$N���������½�%d�㡣",me->query("level")*500),me);
			}
		}
		else
		{
			tell_object(me, "$HIW����ʹ���˵�������㾹Ȼû�ܱ�����ʦ����������̫ʧ���ˣ���");
			
			me->set("hp",100);
			me->set("eff_hp",100);
			me->set("mp",0l);
			if(me->query("level")<80)
			{
				me->add("combat_exp",-me->query("level")*200);
				message_vision(snprintf(msg, 255, "$HIR$Nִ���������������Ե���У�������������������ʧ�ܡ�\n$N���������½�%d�㡣",me->query("level")*200),me);
			}
			else
			{
				me->add("combat_exp",-me->query("level")*500);
				message_vision(snprintf(msg, 255, "$HIR$Nִ���������������Ե���У�������������������ʧ�ܡ�\n$N���������½�%d�㡣",me->query("level")*500),me);
			}
		}
		if(me->query("pro/skill/bahuang_gong"))
		{
			me->set_skill("bahuang_gong",me->query_skill("bahuang_gong",1)-1);
			me->add("pro/skill/bahuang_gong",-1);
			me->FlushMySkill(me);
		}
		if(me->query("lj/pro/skill/liuyang_zhang"))
		{
			me->set_skill("liuyang_zhang",me->query_skill("liuyang_zhang",1)-me->query("lj/pro/skill/liuyang_zhang"));
			me->add("pro/skill/liuyang_zhang",-me->query("lj/pro/skill/liuyang_zhang"));
			me->FlushMySkill(me);
		}
		if(me->query("lj/pro/skill/musci"))
		{
			me->set_skill("musci",me->query_skill("musci",1)-me->query("lj/pro/skill/musci"));
			me->add("pro/skill/musci",-me->query("lj/pro/skill/musci"));
			me->FlushMySkill(me);
		}
		if(me->query("lj/pro/skill/strike"))
		{
			me->set_skill("strike",me->query_skill("strike",1)-me->query("lj/pro/skill/strike"));
			me->add("pro/skill/strike",-me->query("lj/pro/skill/strike"));
			me->FlushMySkill(me);
		}
		if(me->query("pro/lj/int"))
		{
			me->add("int",-1);
			me->add("pro/lj/int",-1);
			me->UpdateMe();
		}
		me->del("lj");
		me->delete_temp("lj");
	}
	else if(me->query_temp("lj/dating") &&me->query_temp("lj/humang")>10)
	{
		tell_object(me, "$HIW���齹�ǵ�˵��������ʦ��ʧ�٣����ļ���٣������ڱ��Ҳ����޼Ƿ���������ش���Ѱ���������䣬����һ����������������ϣ�������ɽ�����ϣ�");
		me->set_temp("lj/shizhong",1);
		me->delete_temp("li/hm");
		me->delete_temp("li/humang");
		me->delete_temp("lj/dating");
	}
	
	return CNpc::do_talk(me,ask);
}
NPC_END;

