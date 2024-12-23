// xiaoyao_kanggl.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxiaoyao_kanggl);

virtual void create()
{
	set_name("����ˮ","kang guangling");
	set("long", "ֻ�����׷�ͯ�գ���ò��ţ�Ц���е��� ��Ϊ�Ͱ������б���һ�����١� ");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);
 	set("icon",old_man1);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 60);
	set("combat_exp", 200000);
	set("score", 50000);
	
	set_skill("blade",100);
	set_skill("xiaoyao_dao",100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 100);
	set_skill("beiming_shengong",100);
	set_skill("liuyang_zhang", 100);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");
	
	set("book_count", 1);
	
	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","�ٵ�");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
	set("no_talk",1);
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() )
	{
		if(me->query_temp("xy/renwu1_8") && !me->query_temp("xy/renwu1_81"))
		{
			tell_object(me,"\n��Ȼ��һ·δЪ������δ�ܸ�����Ϧ֮Լ����ʱ��ң�����������壬��ش�ﶼ��ɢȥ�ˡ�\n");
			me->set_temp("xy/renwu1_81",1);//��Ϧ��۽���
		}
		else if( me->query_temp("xy/renwu1_6") && !me->query_temp("xy/renwu1_61")) 
		{
			tell_object(me,"\nֻ������ˮ���ڸ��٣��Ҹ���ͣͣ���϶�������ʱʱҡͷ��");
			tell_object(me,"���������ǰ��ѯ��ԭ������ˮ�����������󡶹���ɢ����Ӵ˾��죬ÿ��ˣ��ܻ��ź���֡�\n");
		}
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("base_name"), "musicbook1") && EQUALSTR(ob->querystr("skill/name"), "music")
		&& who->query_temp("xy/renwu1_6") && !who->query_temp("xy/renwu1_61") )
	{
		destruct(ob);
		tell_object(who,"$HIC����ˮ���ȵء�������һ����");
		tell_object(who,"$HIC����ˮ���Ե������ʾ��л��");
		tell_object(who,"\n��������⣬����ˮ΢һ�����������������ת���ҵ�����ʦ�ֵܣ�����$HIC��Ϧ������ң��$COM����\n");
		who->set_temp("xy/renwu1_61",1);//֪ͨ����ˮ�μ���Ϧ���
		return 1;
	}
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		AddMenuItem("����ˮ��̹������׵�����", "qipu",me);	
		AddMenuItem("����ˮ��̹��ڽ��������", "jingling",me);

		if(me->query_temp("xy/renwu1_81") && !me->query_temp("xy/renwu1_82"))
		{
			AddMenuItem("����ˮ��Ǹ","zhiqian",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qipu") )
	{
		CContainer *obj;
		if (query("book_count") < 1)
			say("�������ˣ��������Ѿ����͸������ˡ�",me);   
		else
		{
			add("book_count", -1);                  
			say("�ðɣ����ҾͰ����͸����ˡ� ", me);
			message_vision("����ˮ΢Ц�Ŵӻ����ó���һ���飬���˸�$N  ",me);
			obj=load_item("hand_book");//����
			obj->move(me);
			say("�Ȿ���׿�ǧ��Ҫ�������ˡ� ", me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if (DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		{
			say("�㲻��������ң�ɵ����ˣ�������Щ��ʲô��",me);
		}
		else if(me->query_temp("xiaoyao/����")==5)
		{
			me->add_temp("xiaoyao/����",1);
			say( "ʦ���ֹ����ʹ�á�����һЦ������ʵȫ��Ϊ�����Ǻã����¸��������������֪���ˡ�",me);
		}
		else
		{
			me->delete_temp("xiaoyao/����");
			say("������һЦ����û����˭�ù���������ʦ��˵���������ǡ���ң��������������һ�С�",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "zhiqian") )
	{
		if(me->query_temp("xy/renwu1_81") && !me->query_temp("xy/renwu1_82"))
		{
			if(!me->query_temp("xy/renwu1_82") )
				me->set_temp("xy/renwu1_82",1);//����ˮ��֮ʯ��¶�����Լ�
			if(EQUALSTR(me->querystr("family/family_name"), "��ң��")&& EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))//��ң����
				say("����ˮ�Ǻ�һЦ��������ʯʦ��һֱ�����ʦ�壬��������ζ�Ҫȥ����һ�档��",me);
			else
				say(snprintf(msg, 255,"����ˮ�Ǻ�һЦ��������ʯʦ��һֱ�����%s����������ζ�Ҫȥ����һ�档��",query_respect(me)),me);
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);

}
NPC_END;




