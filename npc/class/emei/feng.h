//feng.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_feng);

virtual void create()
{
	set_name("����ʦ̫", "ningfeng shitai");
	set("long", "����һλ����ʦ̫��ֻ����üĿ�״�����������һ�Ѹֵ�����Ȼ��Ȼ���й����ϡ�");
	set("gender", "Ů��");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set("icon", taoistess);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
		set("foolid",3);
	set("max_hp", 3000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	
	
	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("force", 100);
	set_skill("throwing", 80);
	set_skill("dodge", 100);
	set_skill("finger", 100);
	set_skill("parry", 90);
	set_skill("strike", 100);
	set_skill("blade", 100);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("tiangang_zhi", 100);
	set_skill("yanxing_dao", 100);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("blade","yanxing_dao");
	map_skill("parry","yanxing_dao");
	set_inquiry("��ҩ", ask_yao);
	set_inquiry("����", ask_jian);
	
	set("gao_count",3);
	set("jian_count",2);
	create_family("������", 4, "����");
	
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	say("�����ӷ�ƶ�᲻�յ��ӡ�", me);
	say("���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�", me);
	SendMenu(me);
}

static char * ask_yao(CNpc * me, CChar * who)
{
        if (DIFFERSTR(who->querystr("family/family_name"), "������"))
                return "���뱾��������������֪�˻��Ӻ�̸��";

        if (who->query("hp") >= who->query("max_hp"))
                return "��δ�����ˣ�����ҩ����ʲô��";
        
		if (who->PresentName("tianxiang_gao", IS_ITEM))
                return "�����ϲ��Ǵ��ű�����ҩ����";
        
		if (me->query("gao_count") < 1)
                return "�������ˣ�������ҩ�Ѿ������˱��ɵ��ӡ�";
        me->add("gao_count", -1);

		load_item("tianxiang_gao")->move(who);
        return "�������б�����ҩ������ȥ���˰ɡ�";
}

static char * ask_jian(CNpc * me, CChar * who)
{
        
        if (DIFFERSTR(who->querystr("family/family_name"), "������"))
                return "���뱾��������������֪�˻��Ӻ�̸��";
        
		if (me->query("jian_count") < 1)
                return "������û��ʲô�����ø������´������ɡ�";
        if (who->PresentName("ruanjian", IS_ITEM))
                return "�����ϲ��Ǵ�����������ô����Ҫ��";
        me->add("jian_count", -1);
        load_item("ruanjian")->move(who);
        return "��������һ����������ȥ�ðɡ�";
}

NPC_END;
