//xy_fanqiansuei.h	����ذ��ѡ���ǧ��
//�ز� 2002��12��2

NPC_BEGIN(CNxy_fanqiansuei);

void create()
{
	set_name("��ǧ��","fan qiansuei");
	set("gender", "����");
	set("age", 27);
	set("long","һ����ò���õĺ������ߣ����ϻ����ŷ�����һ��ľ�壬�ǰ�����һ������һ���Ļ������ֱ�ߣ���Ȼ����һ����Χ���õ����̡�");

	set("attitude", "peaceful");
	set("icon",young_man2);

	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 22+random(4));
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("hand", 100);
	set_skill("lingboweibu", 100);
	set_skill("beiming_shengong",100);
	set_skill("liuyang_zhang", 100);
	set_skill("zhemei_shou", 100);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");
	
	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","����");
	set("no_huan",1);

};

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && me->query_temp("xy/renwu1_61") 
		&& me->query_temp("xy/renwu1_660") && !me->query_temp("xy/renwu1_661")) 
	{
		tell_object(me,"$HIC\n��ǧ�꿴�˿�Ѫ���£�ҡͷ���������ڿ����Ҳûʲô���ˣ�$HIC����֮�����ڲ�����Ӧ�䣬�����о����̣�ˮ�޳��ƣ����޳���$COM�����������ջ��ǲ��ܲ�͸����߾���ѽ����\n");
		me->set_temp("xy/renwu1_661",1);//��ǧ���޷��ҿ�Ѫ���µ�����
	}
	else if( userp(me) && !is_fighting()&& me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_660"))
	{
		kill_ob(me);
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "Ѫ����") && EQUALSTR(ob->querystr("id"), "zhanyi")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_66") && !who->query_temp("xy/renwu1_660") 
		&& is_fighting() )
	{
		destruct(ob);
		who->set_temp("xy/renwu1_660",1);//����ǧ��Ѫ����
		tell_object(who,"$HIC\n��˵��������ǧ�꣬�㲻��һֱ���Ѫ����һ������ǧ������������㣬��������˷����ң���\n");
		return 1;
	}
	if(EQUALSTR(ob->querystr("name"), "Ⱥ����ͼ") && EQUALSTR(ob->querystr("id"), "qunxing_tu")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_66") 
		&& who->query_temp("xy/renwu1_660") && who->query_temp("xy/renwu1_661") )
	{
		destruct(ob);
		tell_object(who,"$HIC\n��˵����������һ��ͨ������Ⱥ���˶�����Ӧ��Ӧ�������飬���߶������Щ�ô�����");
		tell_object(who,"$HIC��ǧ��ӹ�֮����ϲ��֣�������л������ȴ֮�µ������⣬��ǧ����Ȼ��Ӧ��");
		tell_object(who,"$HIC��ǧ��˵��������ת���ʦ�֣���ʱ�ұض�׼ʱ��Լ��\n");
		who->set_temp("xy/renwu1_66",1);//֪ͨ��ǧ��μ���Ϧ���
		return 1;
	}
	return 0;
}

NPC_END;




