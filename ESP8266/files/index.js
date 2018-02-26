$(document).ready
(
	function ()
	{

		updateVersion() ;
	
		// (
		//	function worker ()
		// 	{
		// 		$.getJSON
		// 		(
		// 			'/time',
		// 			function (data)
		// 			{

		// 				$('span[name="current-time"]').html(data['time'].substr(11, 8)) ;
						
		// 				setTimeout(worker, 5000) ;

		// 			}
		// 		) ;
		// 	}
		// )() ;

		let						setActionAngle									=		function (anAngle)
		{

			console.log(anAngle) ;

			$.post
			(
				'/action',
				{
					'type'														:		'Rotation',
					'rotation_angle'											:		anAngle + ' [deg]'
				},
				function (data)
				{
					
				}
			)
			.done
			(
				function ( )
				{
					
				}
			)
			.fail
			(
				function ( )
				{
					
				}
			)
			.always
			(
				function ( )
				{
					
				}
			) ;

		} ;

		$('.dial').knob
		(
			{
				'min'															:		-90,
				'max'															:		90,
				'change'														:
				function (aValue)
				{
					setActionAngle(aValue) ;
				}
			}
		) ;

		$('button[action="plus"]').click
		(
			function ()
			{

				$('button[action="plus"]').prop('disabled', true) ;

				$('button[action="plus"]').removeClass('btn-info') ;
				$('button[action="plus"]').removeClass('btn-success') ;
				$('button[action="plus"]').removeClass('btn-danger') ;
				$('button[action="plus"]').addClass('btn-warning') ;

				$.post
				(
					'/action',
					{
						'type'													:		'Rotation',
						'rotation_angle'										:		'90.0 [deg]'
					},
					function (data)
					{
						
					}
				)
				.done
				(
					function ( )
					{
						$('button[action="plus"]').removeClass('btn-warning') ;
						$('button[action="plus"]').addClass('btn-success') ;
					}
				)
				.fail
				(
					function ( )
					{
						$('button[action="plus"]').removeClass('btn-warning') ;
						$('button[action="plus"]').addClass('btn-danger') ;
					}
				)
				.always
				(
					function ( )
					{
						$('button[action="plus"]').prop('disabled', false) ;
					}
				) ;

			}
		) ;

		$('button[action="minus"]').click
		(
			function ()
			{

				$('button[action="minus"]').prop('disabled', true) ;

				$('button[action="minus"]').removeClass('btn-info') ;
				$('button[action="minus"]').removeClass('btn-success') ;
				$('button[action="minus"]').removeClass('btn-danger') ;
				$('button[action="minus"]').addClass('btn-warning') ;

				$.post
				(
					'/action',
					{
						'type'													:		'Rotation',
						'rotation_angle'										:		'-90.0 [deg]'
					},
					function (data)
					{
						
					}
				)
				.done
				(
					function ( )
					{
						$('button[action="minus"]').removeClass('btn-warning') ;
						$('button[action="minus"]').addClass('btn-success') ;
					}
				)
				.fail
				(
					function ( )
					{
						$('button[action="minus"]').removeClass('btn-warning') ;
						$('button[action="minus"]').addClass('btn-danger') ;
					}
				)
				.always
				(
					function ( )
					{
						$('button[action="minus"]').prop('disabled', false) ;
					}
				) ;

			}
		) ;
	
	}
) ;