//wulin_jingniting.h љрв•ћь
//«Ў≤® 2002.5.31

WL_BEGIN(CRWuLin_jingniting);

virtual void create()			
{
	set_name("љрв•ћь");
	add_npc("helpnpc_jhlz");
	add_npc("wudang_laodaoshi");
	add_npc("pub_youngwoman");
	add_npc("pub_jiading");
	add_door("ќдЅкіЇЇмјЋЄу","ќдЅкіЇЇмјЋЄу", "ќдЅкіЇљрв•ћь");
	add_door("ќдЅкіЇ±ѓ«пЄу","ќдЅкіЇ±ѓ«пЄу", "ќдЅкіЇљрв•ћь");
	add_door("ќдЅкіЇ÷Ў¬•","ќдЅкіЇ÷Ў¬•", "ќдЅкіЇљрв•ћь");
	add_door("ќдЅкіЇѕгјд…љ„ѓіу√≈","ќдЅкіЇѕгјд…љ„ѓіу√≈", "ќдЅкіЇљрв•ћь");

	set("yuandan",1);

};

WL_END;
