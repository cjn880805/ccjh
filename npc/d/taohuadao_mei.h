// taohuadao_mei.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNtaohuadao_mei);

virtual void create()
{
	set_name( "÷�绨" ,  "mei chaofeng" );
	set("nickname", "��ʬ");
	set("gender", "Ů��");
	set("age", 39);
        set("icon",young_woman1);

	set("long", "÷�绨�ǻ��Ϲ�Ψһ��Ů���ӣ��������ܻ��Ϲ��۰�����ϧ����ʦ�ֳ���ˮ  ������㺣�����͵�ˡ������澭�¾�˽���� ����������꣬����������������ϡ����������ķ�ɡ� ");
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 32);
	set("con", 35);
	set("max_hp",2500);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("repute",-50000);
	
	set("combat_exp", 1000000);
	
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 40);
	set_skill("sword", 80);
	set_skill("literate", 20);
	set_skill("jiuyin_zhua", 90);
	set_skill("luoying_shenjian",90);
	set_skill("bibo_shengong", 90);
	set_skill("anying_fuxiang", 90);
	
	map_skill("force", "bibo_shengong");
	map_skill("parry", "luoying_shenjian");
	map_skill("sword", "luoying_shenjian");
	map_skill("dodge", "anying_fuxiang");
	map_skill("unarmed", "jiuyin_zhua");
	
	create_family("�һ���", 2, "�������");
	
	set_inquiry("�һ���","������ǣ��㶼���˻��᲻֪����");
	set_inquiry("��ʬ","�����ϵ��˶���ô���ҵģ����²��£�����������");
	set_inquiry("��а","������ʦ���Ĵºš�");	
	set_inquiry("�ض�","������ʦ���Ķ�Ů�����ǵ������ԣ����ն�����");
	set_inquiry("�����׹�צ","��ϰ�����׹�צһ��Ҫ�ô���ʬ�塣");
	set_inquiry("�����","�ߣ��������С�Ӱ�������ʦ�磬�Ҿ�����Ź�����");
	set_inquiry("����","�������ҵ�ͽ�ܣ��������ô��");
	set_inquiry("÷�绨","��������ô�����ǰ׳հ���");
	set_inquiry("����ˮ","�����ҵ�ʦ�磬Ҳ���ҵķ������ϧ��������Ǽһﰵ���ˡ�");
	
	
	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "corpse"  ))
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "lengyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}




NPC_END;