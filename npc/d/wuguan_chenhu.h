// wuguan_chenhu.c

//code by Fisho
//date:2000-12-22

VENDOR_BEGIN(CNwuguan_chenhu);

virtual void create()
{
	set_name("���ı�", "chen hu");
	set("title","��ţ��ݽ�ϰ");
	set("long", "����ү�������Ҳæ�˼�ʮ���ˣ���������Я�������ϵ���׳�� ");
	set("gender", "����");
	set("age", 24);
        set("icon",young_man6);
	
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("cuff", 80);
	set_skill("staff", 80);
	set_skill("club", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);

	carry_good("quanpu", 1);
}

virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied") != 1) return 0;
	return 1;
}

VENDOR_END;