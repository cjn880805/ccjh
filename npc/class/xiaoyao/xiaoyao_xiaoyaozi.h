// xiaoyao_xiaoyaozi.c ��ң��

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

ZUSHI_BEGIN(CNxiaoyao_xiaoyaozi);

virtual void create()
{
	set_name("��ңŮ", "xiaoyao nv");
	set("title", "��ң����ʦ");
	set("long","��������ң����ʦ�������ǽ����ϵľ���Ӣ�ƣ�������Ϊ�������� ���ڽ������Ѿ����Ǻܶ���֪���������Ĺ���ȴ������ɲ⡣�������� ");
	set("gender", "Ů��");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);
 	set("icon",old_woman);
	
	set("max_hp", 15500);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 100);
	set("combat_exp", 10000000);
	set("score", 200000);
	
	set_skill("force", 300);
	set_skill("beiming_shengong", 300);
	set_skill("dodge", 400);
	set_skill("lingboweibu", 280);
	set_skill("unarmed", 280);
	set_skill("liuyang_zhang", 150);
	set_skill("parry", 250);
	set_skill("blade", 250);
	set_skill("xiaoyao_dao", 250);
	set_skill("zhemei_shou", 250);
	set_skill("hand", 250);
	set_skill("strike", 250);
	set_skill("literate", 320);
	
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei_shou");
	map_skill("strike", "liuyang_zhang");
	map_skill("parry", "xiaoyao_dao");
	map_skill("blade", "xiaoyao_dao");
	
	prepare_skill("hand","zhemei_shou");
	prepare_skill("strike","liuyang_zhang");
	
	create_family("��ң��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	set("no_chan",1);
	
	carry_object("gangdao")->wield();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("beiming_shengong", 1) < 80) 
	{
		say("����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���", ob); 
		say(snprintf(msg,255,"%s�ı�ڤ���Ƿ�Ӧ��������߰���",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	
	if (ob->query_int() < 35) 
	{
		say(" ����ң���书�����ӡ���ң�����֡�", ob);
		say(" ����ν����ң������ֻ�ܿ����Լ�ȥ����", ob);
		say(snprintf(msg,255," ����%s�������ƺ����д���߰���",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	command("smile");
	say(" �벻���������Ͼ�Ȼ�����˿��Լ̳��ҵ���ң�ķ���");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
//	ob->set("xiaoyao/xiaoyaozi", 1);
	ob->set("title","��ң�ɻ���ʹ��");
	ob->UpdateMe();
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->query("xiaoyao/xiaoyaodao")>=9)		return 0;
	if(who->query("xiaoyao/���þ���")==1)		return 0;
	if(DIFFERSTR(ob->querystr("name"), "����") )		return 0;
	destruct(ob);
	say("�������ͽ�����㲻������й¶���ž��У���ƫƫ�����̲�סҪ��ȥ��Ūһ����", who);
	say("�������������ı���Ū�����Ǳ������", who);
	say("Ҫ������ο������û�����ң����ɽ�����۲���ݵķ��ϣ��ҲŲ������Ĺ��㣡", who);
	say("���ҹ���ȥ��ȥ��ʦ������ȥ�Ұ��Ƶ����š��´�Ҫ����Υ�����������������ʰ�㣡", who);
	SendMenu(who);
	who->add("hp",-200);
	who->add("xiaoyao/����", 1);
	who->add("xiaoyao/xiaoyaodao", 1);
	return 1;
}
*/

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "��ң��ʯ��" ))
		return notify_fail("�����������");
	char msg[255];
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
	else if(EQUALSTR(ob->querystr("name"),"����"))
	{
		if(who->query("xiaoyao/xiaoyaodao")>=9)		return 0;
		if(who->query("xiaoyao/���þ���")==1)		return 0;
		say("�������ͽ�����㲻������й¶���ž��У���ƫƫ�����̲�סҪ��ȥ��Ūһ����", who);
		say("�������������ı���Ū�����Ǳ������", who);
		say("Ҫ������ο������û�����ң����ɽ�����۲���ݵķ��ϣ��ҲŲ������Ĺ��㣡", who);
		say("���ҹ���ȥ��ȥ��ʦ������ȥ�Ұ��Ƶ����š��´�Ҫ����Υ�����������������ʰ�㣡", who);
		SendMenu(who);
		who->add("hp",-200);
		who->add("xiaoyao/����", 1);
		who->add("xiaoyao/xiaoyaodao", 1);
		destruct(ob);
		return 1;
	}
	return 0;
}

static char * ask_me(CNpc *who,CChar *me)
{
	char msg[255];
	if(DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
	{
		message_vision("�������ң���ˣ�����Щ��ʲô��",me,who);
		return 0;
	}
	if (me->query("xiaoyao/xiaoyaozi") !=1)
	{
		me->set("xiaoyao/xiaoyaozi",1);
		me->set("xiaoyao/xiaoyaodao", 9);
		CContainer * ob = load_item("blade_2");
	    ob->move(me);
		message_vision(snprintf(msg, 255, "$n˵����ͽ������һ�δ��������������¶�ҪС�ģ�\nʦ�����ھͰ��Լ�ʹ�ö���ĵ��͸��㣬�����ϧ��\n$n��$N����1��%s��",  ob->name()), me, who);
		return 0;   
	}
	else 
		return "�������⣬���¶�Ҫ�Լ�С�ġ�";
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query_temp("xy/��ң��") )
	{
		if(!me->query("xy/renwu1"))
		{
			if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))//��ң����
			{
				switch(me->query_temp("xy/lingting"))
				{
				case 0:
					say("�������ңŮ�������ȥ�������ε��Ӱݼ�ʦ������",me);
					say("��ңŮ����һ�ڣ�΢Ц���������������ʦͽ��ȴҲ���ؾ��񣬷������Υ��ң֮���ˡ���",me);
					say("˵���䣬һ����͵������ѽ��㻺������",me);
					me->add_temp("xy/lingting",1);
					break;
				case 1:
					say("��ңŮ�����������֪Ϊʦ�˴μ��ٶ��Ȼ�������Ϊ���£���",me);
					say("��������ңŮ�����ֱ�ȭ��������ϴ����������",me);
					me->add_temp("xy/lingting",1);
					break;
				case 2:
					say("��ңŮ���յ�������ǰ����ǰ�����������ݷ����ʦ��;�У�������������δ������׺�ʦ�㣬����֪�ֳ���ң�Ӳ�δ��ȥ����",me);
					say("��ңŮ���յ�����ֻ�ǲ׺�Сʦ�û�δ˵�꣬��Ҵ����ˣ��������ƺ�˵�ˡ���ߧ�����֡���",me);
					say("�㾪�ȵ��ʵ���������ߧ��Ϊ���⣿��",me);
					me->add_temp("xy/lingting",1);
					break;
				case 3:
					say("��ңŮ̾�˿�����������ϡ�ǵ�����ʱ�ֳ������������ߧ���ء��������ںδ����Ͳ��ö�֪�ˡ�Ϊʦ��������ң���Է������ɳû�����Ѱ�Ҹ��ص��£��Ͱ��������ˡ���",me);
					say("��ңŮ�������������뵱�������ֲ���ǿ��һ����Ե��������ң�������ȥ�ɡ���",me);
					me->add_temp("xy/lingting",1);
					break;
				case 4:
					say("��ңŮ�ֵ��������ʦ�ֲ���ǿ�ǣ����²�����������ѯ�����ܵ��棬Ϊʦ�Ծ��ڴˣ������Ϊ֮�ɡ���",me);
					say("�����ߵ�򣺡����ӽ���̻塱��",me);
					me->delete_temp("xy/lingting");
					me->delete_temp("xy/��ң��");
					me->set("xy/renwu1",1);//������ң�����һ���֣�Ѱ�Ҹ��ء�����ȥ�����Ӵ��������ص���Ϣ
					break;
				}
			}
			else//����ң����
			{
				if(! strlen(ask))
				{
					say("�������ңŮ��˫��������������ѯ�ʵ�������֪ǰ���㷢��ң���Ϊ���£���",me);
					say(snprintf(msg, 255, "��ңŮ����һ�ڣ�΢Ц��������λ%s���ض��������λǰ����ֻ��Ϊ���������ֳ�ʧ����ʮ�꣬�������ţ����ڵõ���Ϣ���䲢δ��ȥ����",query_respect(me)),me);
					say("��ңŮ΢Ц��������������������ɴ��ͷ������ɧ�ű��ţ��鲻����������λͬ����������Ѱ�������ֳ����䣡��",me);
					say(snprintf(msg, 255, "��ңŮ���ڴ����������㣺����֪��λ%s�ɷ�Ը����������",query_respect(me)),me);
					AddMenuItem("Ը��", "yes", me);
					AddMenuItem("��������æ������Ͼ����", "no", me);
				}
				else if(!strcmp(ask, "yes") )
				{
					say(snprintf(msg, 255, "��ңŮ̾�˿���������ʵ���»�ãã��ͷ������һ˿������ʾ�����뱾�ɸ����йأ�Ȼ���ؾ����ںδ����Ͳ��ö�֪�ˡ����ֳ��Ĵ�ͽ�ܲ���ǿ�ǣ����²�����������ѯ�����ܵ��档Ѱ�Ҹ��ص��£��Ͱ���%s�ˣ���",query_respect(me)),me);
					me->set("xy/renwu1",1);//������ң�����һ���֣�Ѱ�Ҹ��ء�����ȥ�����Ӵ��������ص���Ϣ
					me->delete_temp("xy/��ң��");
				}
				else if(!strcmp(ask, "no") )
				{
					say(snprintf(msg, 255,"��ңŮһ��ʧ���Ŀ���һ�ۣ���������ˣ��Ͳ�������%s�ˡ���",query_respect(me)),me);
					me->delete_temp("xy/��ң��");
				}
			}
		}
	}
	else
	{
		set_inquiry("��ɽ",ask_me);
		set_inquiry("����","�������Ͼ���δ����ɣ��Ͻ�ʹ�á�");
		if(me->query("xy/renwu1") && !me->query("xy/renwu2"))
			set_inquiry("��������ʧ��",ask_lin);
		return CNpc::do_talk(me,ask);
	}
	SendMenu(me);
	return 1;
}

static char * ask_lin(CNpc *who,CChar *me)
{
	me->del("xy");
	me->delete_temp("xy");

	CContainer * yinyue_si;
	yinyue_si=me->present("yingyue si");
	if(yinyue_si)
		destruct(yinyue_si);

	return "��Ȼ��ˣ�����Ҳ����ǿ���ˡ�";
}
ZUSHI_END;




