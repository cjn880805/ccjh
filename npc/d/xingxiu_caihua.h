// xingxiu_caihua.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_caihua);

virtual void create()
{
	set_name("�黨��", "caihua zi" );
	set("gender", "����" );
	set("title", "��������");
	set("nickname", "������");
	set("age", 38);
	set("long", "�黨���������ɵ�һ��С��ޣ��书�䲻�ã���������а�������������Ҹ�Ů���ǹٸ�ͨ���ķ��ˣ��ʶ�������������Ҳ��������������ӡ� ");
	set("str", 25);
	set("dex", 30);
	set("con", 17);
	set("int", 15);
	set("shen_type", -1);
        set("icon",young_man4);
	
	set_skill("unarmed", 20);
	set_skill("force", 50);
	set_skill("dodge", 95);
	set_skill("zhaixinggong", 95);
	map_skill("dodge","zhaixinggong");
	
	set("combat_exp", 25000);
	
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	
	create_family("������", 5, "����");
	
	set("attitude", "peaceful");
	
	carry_object("pink_cloth")->wear();
	add_money( 1000);

	set_inquiry("name","��Ҳ�ǲ�����������˭�ˣ��������������ź��黨�ӡ�");
	set_inquiry("�ɻ�","�ǿ���ѧ�ʣ��Ҳ������̡�");
	set("no_huan",1);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && !is_fighting())
	{
		if ( EQUALSTR(me->querystr("family/family_name"), "������") )
			say("�������ɽ��׽�˸�С�����ˮ�鼫�ˣ��͹����ҵ���ң�����Ҫ��Ҫ��ȥ���ԣ�");
		me->set_temp("marks/��",0l);
	}
}


virtual void attempt_apprentice(CChar * ob)
{
	say("��ѧ�ҵĲɻ��񼼣�û�Ŷ���", ob);
	SendMenu(ob);
	return;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if (DIFFERSTR(me->querystr("family/family_name"), "������")) 
		say("�ٸ����׽�����", me);
	else 
	{
		if (DIFFERSTR(ob->querystr("base_name"), "coin") ) 
		{
			if (EQUALSTR(me->querystr("gender"), "Ů��"))
			{
				say("�黨������������������һ�¡�", me);
				say("�벻��ʦ��Ҳ��������á�", me);
			}
			else 
			{
				say("�黨�Ӹ�������ľ���һ����",me);
                say("��лʦ�֡�", me);
            }

            say("�Բ�����С��������ϱ���֪���ĸ��쵰�����ˣ���������Խ���˯һ����", me);
			me->set_temp("marks/��", 1);
		}
		else
		{
			say("Ǯ���е��ǣ��㻹�Ǹ��ҵ���ʲô�ɡ�", me);
		}
	}

	SendMenu(me);
	return 1;
}

NPC_END;