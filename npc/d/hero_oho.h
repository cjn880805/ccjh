// wuguan_xiaofei.c

//code by oho
//date:2000-12-22

VENDOR_BEGIN(CNhero_oho);

virtual void create()
{
	set_name("�������", "oho");
	set("title","����Ӣ��");
	set("long", "����һ���������˵����ˣ�������˪��������ϡ���Կ��ü�һЩ����ʧ�˵ĵ�Ӣ�����š� ");
	set("gender", "����");
	set("age", 34);
        set("icon",young_man4);
        set("per", 34);
	set_skill("blade", 180);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("throwing", 80);
	set_skill("tangshoudao", 180);
	set_skill("dongyangdaofa", 80);
	set_skill("songshan_sword", 80);
	set_skill("taishan_sword", 80);
	set_skill("hengshan_sword", 80);
	set_skill("hengshan_jian", 80);
        set_skill("zhongpingqiang", 80);
        set_skill("wuhuduanmendao", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
	set_inquiry("����书", "�书���һ��𣿣�");
	set_inquiry("����", "�ܾ���ǰ���ͺ�һ�θ���һ���������ˡ�");

	carry_good("caoxie", 20);
	carry_good("jiu_mijiu", 10);
	carry_good("zheshan", 20);
	carry_good("wuqing_sword", 1);
	carry_good("abab_sword", 1);
	carry_good("panguanbi", 1);
	carry_good("xem_sword", 1);
	carry_good("mandao", 10);
	carry_good("qinqin_sword", 1);
	carry_good("changqiang", 4);
	carry_good("hothammer", 20);
	carry_good("shutonggun", 20);
	carry_good("ruanjian", 20);
	carry_good("tongren", 2);
	carry_good("tiepipa", 2);
	carry_good("tiejiang", 2);
	carry_good("cleansword", 1);
	carry_good("jiujiebian", 5);
	carry_good("wodao", 5);
	carry_good("tie_gan", 2);
	carry_good("fork", 2);
	carry_good("zuguo5", 3);
	carry_good("zijinchui", 2);
	carry_good("longquansword", 1);
	carry_good("leizhendang", 1);
	carry_good("baojia", 1);
	carry_good("qin", 1);
	carry_good("plumsword", 1);
	
	
	}

virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=2) return 0;
	return 1;
}
//ע�⣬��Ϊ����ʦ��,����ݽ�Ǯ�Ժ�Ϳ��Ե�����ѧϰ
VENDOR_END;