//qing_yuan.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_yuan);

virtual void create()
{
	set_name("��Ե����", "qingyuan biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",94);
	set("age", 30);
	set("shen_type", 1);
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1050);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("strike", 30);
	set_skill("qianye_shou", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "qianye_shou");
	map_skill("parry", "qianye_shou");

	prepare_skill("strike", "qianye_shou");

	create_family("������", 40, "����");
    carry_object("xu_cloth")->wear();
};

virtual void init(CChar * me)
{	
	CNpc::init(me);

	if(userp(me) && !is_fighting() ) 
	{
		remove_call_out(do_speaking);
		call_out(do_speaking, 1);
	}
}

static void do_speaking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if ( random(5) < 1 ) 
	{	
		switch( random(4) ) 
		{
		case 0:
               me->say("����ǰ��һ��������������¾ͳ�����κͱ��ߵ���¥û���֡���������");
		       break;
		case 1:
               me->say("��������ȫ�ø�֭����Ļ����Ҹ��������������Ǿ��Ǳ�ɲ�ӬҲ�ɲ���ȥ��");
		       break;
		case 2:
               me->say("�úô��ű𶯣��Ȼ����Ȼ������ǳ�ȥ�����������Լ�Ҫ����ҿɲ��ܣ�");
		       break;
		case 3:
               me->say("�٣����������پ޼����������ﱻ�ع�����������������������һ����");
		       break;
		}
	}
}

NPC_END;
