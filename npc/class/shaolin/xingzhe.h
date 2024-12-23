//xingzhe.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_xingzhe);

virtual void create()
{
	set_name("����", "xingzhe");
	set("title", "���ֵ�ɮ");
	set("long",	"����һλ�����ķ������ߣ���˪���棬��ɫ�Ҵң��ƺ����ڰ�һ�����¡�");

	set("gender", "����");
	set("attitude", "heroism");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",112);
	set("chat_chance", 3);

	set("age", 35);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);
	set("combat_exp", 20000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("cibei_dao", 50);
	set_skill("hunyuan_yiqi", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
};

virtual char * chat_msg()
{
	switch(random(12))
	{
	case 0:
		return 	"����˵������˵������ɽɽ������һ���̺����Ͻ�ħ�󷨵Ľ�շ�ħȦ�����з�ҷ�����";
	case 1:
        return  "����˵�����׽��Ϊ����ƪ������ƪ����ƪ��ȭ��ƪ�Ĳ�������ǰ�㶼��ɢʧ������";
	case 2:
		return  "����˵��������ȭ���ͺ�������������һ�����ƽ�������Ц����Ϸ�ҳ������˵ı��⡣";
	case 3:
        return  "����˵��������ʮ���޺����������ޱȣ�����������߿�˵�Ƿ�ë��ǣ�������һ���˲š�";
	case 4:
        return  "����˵�������µ������϶��£���������ʥɮ��ʮ���޺��������ߣ�����ʦ���ű���ȡ�";
	case 5:
        return  "����˵��������Ժ��������ʹ��ʦ��ȫ��������ɮ�����������Ǵ���Ҳ���ҿ�һ����";
	case 6:
        return  "����˵���������²ؾ�¥�ؾ�֮�������º��С��𷨾��䣬�书�ؼ�������˵������������";
	case 7:
        return  "����˵�������µ�����Ҫϰ������ɵ����������ͷ��߿���ȡ��е������黹��˾��";
	case 8:
        return  "����˵������������������ɮ��������¥�������޷𷨣��߲㴰��ƽ̨�ϸ����������";
	case 9:
        return  "����˵�������־�����ʮ����ר��һ�ţ����Ǵ��кô����������ڹ����գ���������ǿ��";
	case 10:
        return  "����˵�������µ������ܽϼ�սʤʦ�𱲣�����������ͬ�࣬��ʦѧϰ����������ա�";
	case 11:
		random_move();
		return 0;
	};
	
	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if ( userp(me) && !is_fighting()
		&& ! environment()->query("no_fight")
		&& ( DIFFERSTR(me->querystr("family/family_name"), "������") && EQUALSTR(me->querystr("class"), "bonze")) )
	{
		say("������޳�������ͽ���������ɣ�����");
		set_leader(me);
		remove_call_out(do_killing);
		call_out(do_killing, 1, me->object_id()); 
	}       
}

static void do_killing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	me->kill_ob(who);
}

NPC_END;
