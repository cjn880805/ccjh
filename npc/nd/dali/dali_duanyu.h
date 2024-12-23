// dali_duanyu.h ����
//sound 2001-07-16

NPC_BEGIN(CNdali_duanyu);

virtual void create()
{
	set_name("����", "duan yu");
	set("nickname", "��������");
	set("gender", "����");
	set("age", 20);
	set("long", "����һ�����������������ӡ������Լ⣬����һ�������Ĵ�����\n");
	set("attitude", "peaceful");
	
	set("str", 12);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",young_man1);	
	
	set("chat_chance", 1);
	
	set_inquiry("����", "�����Ǹ��õط���ɽ��ˮ�㣬�羰���ˡ�");	
	set_inquiry("������", "����������ֻ������磬������û���ҷ������");
	set_inquiry("��ʦ", "��....���ҵ�ʦ�������ӡ����Ӻ�ׯ�ӣ����ǵ�ѧ���һ�ûѧȫ�ء�");
	
	set("hp", 5000);
	set("max_hp", 5000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor",300);
	
	set("combat_exp", 2000000);
	set("shen_type", 1);
	
	set_skill("force", 220);		// �����ڹ�
	set_skill("beiming_shengong", 220);	// ��ڤ��
	set_skill("finger", 220);		// ����ָ��
	set_skill("six_finger", 220);		// ������
	set_skill("dodge", 220);		// ��������
	set_skill("lingboweibu", 250);		// �貨΢��
	set_skill("parry", 180);		// �����м�
	
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "six_finger");
	map_skill("finger", "six_finger");
	prepare_skill("finger","six_finger");
	
	carry_object("gangjian");
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual char * chat_msg()						//NPC�Զ�����
{
	switch(random(2))
	{
	case 0:
		return 	"����̾�˿����������þ�û������һ��Ⱦ��ˣ���֪���������Σ���";
	case 1:
		return 	"����̾�˿�����������������ʱ���ټ������̰�������";
	}
	return 0;
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("xy/renwu1_2") && !me->query_temp("xy/renwu1_21")) 
	{
		tell_object(me,"\n$HIC����ճյ����Ŷ���Զ�������������");
		tell_object(me,"$HIC���貨΢����������������ת���������������ա�����δ�£�����������������ȣ��������͡�");
		tell_object(me,"$HIC������֪�����������������ˡ���\n");
		tell_object(me,"$HIC����̾�˿�������");
		tell_object(me,"$HIC���������ɣ�������أ��Ӿ������ʳ�¶�������޼ӣ�Ǧ��������");
		tell_object(me,"$HIC���ٶ�룬��ü���ꡣ�������ʣ������ʡ���");
		tell_object(me,"$HIC���ɽ�㣬����������֮��������ȴ����������Ū��֧�����飬��������Ī�ꡣ��\n");
		me->set_temp("xy/renwu1_21",1);//������Ҫ����
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "����") && EQUALSTR(ob->querystr("id"), "bojuan")
		&& who->query_temp("xy/renwu1_2") && !who->query_temp("xy/renwu1_3") )
	{
		destruct(ob);
		tell_object(who,"\n�����ϲ��������С������ؽ��������ս��˻��У�Ȼ��м��������ʼ����⣡");
		tell_object(who,"�㽫ǰ��һһ�����˵������ѯ�ʹ��ڲ軨����װ�ع���֮�¡�\n");
		
		CContainer * bot = load_item("baozi");
		bot->set_name("����", "hua zhong");
		bot->set("long","����һ����ɫ�����ӡ�");
		bot->set("value", 1);      
		bot->set("unit", "��");
		bot->move(who);
		tell_object(who,"����ȡ��һ�Ż��ֽ����㡣");
		tell_object(who,"����˵������ֻ�к������$HICʯ��¶ʯ����$COM���ܽ��������ɡ���\n");
		who->set_temp("xy/renwu1_3",1);//�õ�����������
		return 1;
	}
	return 0;
}
NPC_END;