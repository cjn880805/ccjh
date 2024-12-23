// xiaoyao_fengas.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxiaoyao_fengas);

virtual void create()
{
	set_name("���䳵", "feng asan");
	set("long", "��˵������³��ĺ��ˣ������ĵ�һ�����ɽ��� ");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("class", "alchemist");
	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
 	set("icon",young_man4);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("blade",50);
	set_skill("xiaoyao_dao",50);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("lingboweibu", 50);
	set_skill("beiming_shengong",50);
	set_skill("liuyang_zhang", 50);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");
	
	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","�ɽ�");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();		//��blade��Ϊgangdao��lanwood 2000-12-31
	set("no_talk",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		AddMenuItem("���䳵��̹��ڻ��ص�����", "jiguan",me);	
		AddMenuItem("���䳵��̹��ھ��е�����", "jingling",me);

		if(me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_63"))
		{
			AddMenuItem("ת�湫�䳵������Ϧ���֮��","qixi",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jiguan") )
	{
		if (random(100)<70)
			say( "������ƻ��ط������е��س����ô�Ҽ�Ц�ˡ�",me);   
		else
			say("�����ң����ڿ����ء�������֥�鿪�š��������������Ц ",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if (me->query("xiaoyao/����")>=1)
		{
			me->del("xiaoyao/����");
			if(random(4))
			{
				CContainer * ob = load_item("blade_1");
				ob->move(me);
				message_vision(snprintf(msg, 255, "$n˵�����������ְ�ʦ�������ǲ��ǣ�\n$n��$N����1��%s��",  ob->name()), me, this);
			}
			else
			{
				say( "������̫���ˣ��������������ù��ˡ�",me);
				SendMenu(me);
			}
		}
		else
		{
			if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
			{
				say("�㲻��������ң�ɵ����ˣ�������Щ��ʲô��",me);
			}
			else if(me->query_temp("xiaoyao/����")==2)
			{
				me->add_temp("xiaoyao/����",1);
				say("������һЦ����������ʦ��ʹ�ù�һ�Σ���Ѥ����Ŀ���������Ƿ�׹�ĳ��棬�����񶼻��ǵ����������",me);
			}
			else
			{
				me->delete_temp("xiaoyao/����");
				say( "�����书��˵��һ����ǿ��ʽ�������޵С�����ʦ��������δ����ɣ�����ʹ�ü��κ�ͻ��������á�",me);
			}
			SendMenu(me);
		}
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61") )
		{
			if(!me->query_temp("xy/renwu1_63") )
				me->set_temp("xy/renwu1_63",1);//֪ͨ����μ���Ϧ���
			say(snprintf(msg, 255,"���䳵�Ǻ�һЦ���������ð������ǡ����Ȱ��ѡ������ֿ����ٴ�����ˣ�����%s�پ���ת��һ���ҵ�����ʦ�ֵܣ���",query_respect(me)),me);
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);
}
NPC_END;




