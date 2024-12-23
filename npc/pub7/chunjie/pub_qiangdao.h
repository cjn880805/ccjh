//pub_qiangdao.h

NPC_BEGIN(CNpub_qiangdao);

void create()
{
	set_name("ÀñÎïÇ¿µÁ", "qiang dao");

	set("icon", 16);
	set("gender", "ÄÐÐÔ");
	set("level", 157);
	set("age", 45);
	set("shen_type", -1);

	set("max_hp", 1000);
	set("max_mp", 100);
	set("mp", 100);
	set("mp_factor", 50);

	set("combat_exp", 1000);
	call_out(do_die, 900);	
	carry_object("chunjie_ld", 1);

}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

NPC_END;
